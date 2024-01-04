/*
Assignment-3
Group Members:
Atishay Jain-20CS3008
Gaurav Malakar-20CS10029
Monish Natrajan-20CS30033
Roopak Priydarshi-20CS30042
*/

// function to produce new nodes and edges
void producer(int *graph, int *probs, int *slots)
{
    int N = graph[MAX_NODES * MAX_DEGREE];
    int nProbs = probs[MAX_NODES * MAX_DEGREE];

    srand(time(NULL));
    // generating random m and k
    int m = (rand() % 21) + 10;
    int k = (rand() % 20) + 1;

    int tmp = nProbs;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++) // new m node connecting to k old nodes
            probs[++tmp] = N + i + 1;
    }

    // adding the nodes in a slot
    int nw = 1, sSize, st;
    for (int i = 0; i < 9; i++)
    {
        st = i * (MAX_NODES / 10);
        sSize = slots[st];
        for (int j = 0; j < m / 10; j++)
            slots[st + sSize + j + 1] = N + nw++;
        slots[st] = sSize + (m / 10);
    }

    // for the last slot
    st = 9 * (MAX_NODES / 10);
    sSize = slots[st];
    for (int j = 0; j < m - (9 * (m / 10)); j++)
        slots[st + sSize + j + 1] = N + nw++;
    slots[st] = sSize + m - (9 * (m / 10));

    // selecting k distinct nodes
    set<int> nds;
    while (nds.size() < (unsigned long)k)
        nds.insert(probs[rand() % nProbs]);

    int i = 0;
    // adding the nodes and edges to the graph
    for (int ki : nds)
    {
        int adLS = graph[MAX_DEGREE * ki];
        for (int j = 0; j < m; j++)
        {
            probs[++tmp] = ki;
            graph[(MAX_DEGREE * ki) + adLS + j] = N + j + 1;
            graph[(MAX_DEGREE * (N + j + 1))]++;
            graph[(MAX_DEGREE * (N + j + 1)) + i + 1] = ki;
        }
        graph[MAX_DEGREE * ki] = adLS + m;
        i++;
    }

    // updating the count of probs and nodes
    probs[MAX_NODES * MAX_DEGREE] = tmp;
    graph[MAX_NODES * MAX_DEGREE] = N + m;
    return;
}