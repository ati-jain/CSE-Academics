/*
Assignment-3
Group Members:
Atishay Jain-20CS3008
Gaurav Malakar-20CS10029
Monish Natrajan-20CS30033
Roopak Priydarshi-20CS30042
*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <queue>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define INPUT_FILE "facebook_combined.txt"
#define MAX_NODES 7000
#define MAX_DEGREE 2500
#define INF 1000000000
#define PRODUCER_COOLDOWN 50
#define CONSUMER_COOLDOWN 30

typedef priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minpq;

#include "consumer.cpp"
#include "producer.cpp"

// counts the number of nodes in the graph
int node_count()
{
    FILE *fp;
    fp = fopen(INPUT_FILE, "r");
    int u, v;
    int n = 0;
    while (fscanf(fp, "%d %d", &u, &v) != EOF)
        n = max(n, max(u, v));
    return n;
}

// adds an edge to the graph
void addedge(int *graph, int u, int v)
{
    int *temp = graph + u * MAX_DEGREE;
    temp[0]++;
    temp[temp[0]] = v;
}

// creates the graph
void create_graph(int *graph, int *probs, int n)
{
    for (int i = 0; i <= n; ++i)
    {
        graph[i * MAX_DEGREE] = 0;
    }

    FILE *fp;
    int nProbs = 0;
    fp = fopen(INPUT_FILE, "r");
    int u, v;
    while (fscanf(fp, "%d %d", &u, &v) != EOF)
    {
        // considering undirected graph, adding edges in both direction
        addedge(graph, u, v);
        addedge(graph, v, u);
        probs[++nProbs] = u;
        probs[++nProbs] = v;
    }
    probs[MAX_NODES * MAX_DEGREE] = nProbs;
}

// graph[i*MAX_DEGREE] stores the degree of node i
// graph[i*MAX_DEGREE + j] stores the jth neighbour of node i
// graph[MAX_NODES*MAX_DEGREE] stores the number of nodes in the graph (n)

int main(int argc, char const *argv[])
{
    // seeing if flag is passed or not
    bool flag = false;
    if (argc > 1)
    {
        if (strcmp(argv[1], "-optimize"))
        {
            cerr << "Invalid flag!\n";
            exit(1);
        }
        flag = true;
    }

    // shared memory
    int shmid = shmget(IPC_PRIVATE, (MAX_NODES * MAX_DEGREE + 1) * sizeof(int), IPC_CREAT | 0666);
    int shmid_probs = shmget(IPC_PRIVATE, (MAX_NODES * MAX_DEGREE + 1) * sizeof(int), IPC_CREAT | 0666);
    int shmid_slots = shmget(IPC_PRIVATE, MAX_NODES * sizeof(int), IPC_CREAT | 0666);
    int shmid_dists = shmget(IPC_PRIVATE, 10 * MAX_NODES * sizeof(int), IPC_CREAT | 0666);
    int shmid_prnts = shmget(IPC_PRIVATE, 10 * MAX_NODES * sizeof(int), IPC_CREAT | 0666);

    // attaching shared memory
    int *graph = (int *)shmat(shmid, NULL, 0);
    int *probs = (int *)shmat(shmid_probs, NULL, 0);
    int *slots = (int *)shmat(shmid_slots, NULL, 0);
    int *dists = (int *)shmat(shmid_dists, NULL, 0);
    int *prnts = (int *)shmat(shmid_prnts, NULL, 0);

    for (int i = 0; i < 10 * MAX_NODES; i++)
        dists[i] = INF;

    int n = node_count();
    // using last index to store the number of nodes in graph
    graph[MAX_NODES * MAX_DEGREE] = n;
    create_graph(graph, probs, n);
    int st, nd = 1;

    // adding nodes to each slot
    for (int i = 0; i < 9; i++)
    {
        st = i * (MAX_NODES / 10);
        slots[st] = n / 10;
        for (int j = 1; j <= n / 10; j++)
            slots[st + j] = nd++;
    }
    st = 9 * (MAX_NODES / 10);
    slots[st] = n - (9 * (n / 10));
    for (int j = 1; j <= n - (9 * (n / 10)); j++)
        slots[st + j] = nd++;

    int producer_timer = PRODUCER_COOLDOWN, consumer_timer = 0;
    while (1)
    {
        int sleep_time = min(producer_timer, consumer_timer);
        sleep(sleep_time);
        producer_timer -= sleep_time;
        consumer_timer -= sleep_time;

        if (producer_timer == 0)
        {
            pid_t pid = fork();
            if (pid == 0)
            {
                producer(graph, probs, slots);
                exit(0);
            }
            waitpid(pid, NULL, 0);
            // updating the no. of nodes
            n = graph[MAX_NODES * MAX_DEGREE];

            producer_timer = PRODUCER_COOLDOWN;
            cout << "Graph Updated by Producer\n\n";
            fflush(stdout);
        }

        if (consumer_timer == 0)
        {
            int start = 0, range = n / 10;

            vector<pid_t> child_pids;
            for (int i = 1; i <= 10; ++i)
            {
                pid_t pid = fork();
                if (pid == 0)
                {
                    if (flag)
                        // clock_t start1 = clock();
                        consumer_optimized(graph, n, slots + ((i - 1) * MAX_NODES / 10), dists + ((i - 1) * MAX_NODES), prnts + ((i - 1) * MAX_NODES), "output_" + to_string(i) + ".txt");
                    // start1 = clock() - start1;
                    else
                        // clock_t start2 = clock();
                        consumer(graph, n, slots + ((i - 1) * MAX_NODES / 10), "output_" + to_string(i) + ".txt");
                    // start2 = clock() - start2;
                    // printf("Optimised time: %lf s\n", (double)start1/CLOCKS_PER_SEC);
                    // printf("Unoptimised time: %lf s\n\n", (double)start2/CLOCKS_PER_SEC);
                    // fflush(stdout);
                    exit(0);
                }
                child_pids.push_back(pid);
                start += range;
            }
            for (auto pid : child_pids)
                waitpid(pid, NULL, 0);

            consumer_timer = CONSUMER_COOLDOWN;
            cout << "Shortest path calculation done!\n\n";
            fflush(stdout);
        }
    }

    // detaching the shared memory
    shmdt(graph);
    shmdt(probs);
    shmdt(slots);
    shmdt(dists);
    shmdt(prnts);

    // deleting the shared memory
    shmctl(shmid, IPC_RMID, NULL);
    shmctl(shmid_probs, IPC_RMID, NULL);
    shmctl(shmid_slots, IPC_RMID, NULL);
    shmctl(shmid_dists, IPC_RMID, NULL);
    shmctl(shmid_prnts, IPC_RMID, NULL);

    return 0;
}
