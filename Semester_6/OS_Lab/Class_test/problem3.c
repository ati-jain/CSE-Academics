// Atishay Jain
// 20CS30008
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

pthread_mutex_t arrMutex;
pthread_mutex_t arrBMutex;

#define UNPROCESSED 0
#define PROCESSED 1
int **M;
int m, n;

void *order_thread_function(void *args)
{
    printf("I am order\n");
    int *A = args;
    int *B = args + sizeof(int *);
    for (int time = 0; time < 30; time++)
    {
        for (int i = 0; i < 1000; i++)
        {
            pthread_mutex_lock(&arrMutex);
            if (B[i] == UNPROCESSED)
            {
                printf("Order: detected updated element at row %d\n", A[i]);
                B[i] = PROCESSED;
                pthread_mutex_unlock(&arrMutex);
            }
            else
            {
                pthread_mutex_unlock(&arrMutex);
            }
        }
    }
    pthread_exit(0);
}

void *chaos_thread_function(void *args)
{
    printf("I am chaos\n");
    int *A = args;
    int *B = args + sizeof(int *);
    for (int time = 0; time < 30; time++)
    {
        int i = rand() % m;
        int j = rand() % n;
        int k = (rand() % 1000) + 1;
        M[i][j] = k;
        printf("Chaos: updated element at cell %d x %d with value %d\n", i, j, k);
        for (int x = 0; x < 1000; x++)
        {
            pthread_mutex_lock(&arrMutex);
            // checking for an empty entry
            if (B[x] != UNPROCESSED)
            {
                B[x] = UNPROCESSED;
                pthread_mutex_unlock(&arrMutex);
                pthread_mutex_lock(&arrBMutex);
                A[x] = i;
                pthread_mutex_unlock(&arrBMutex);
                break;
            }
            else
            {
                pthread_mutex_unlock(&arrBMutex);
            }
        }
        sleep(2);
    }
    printf("CHAOS ENDS\n");
    pthread_exit(0);
}

int main()
{
    scanf("%d%d", &m, &n);
    M = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
        M[i] = (int *)malloc(sizeof(int) * n);
    srand(time(NULL));
    pthread_mutex_init(&arrMutex, NULL);
    pthread_mutex_init(&arrBMutex, NULL);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            M[i][j] = (rand() % 1000) + 1;
    }
    printf("Random matrix M is created\n");

    // Creating shared memory explicitly because mentioned in the question
    int shmidA = shmget(IPC_PRIVATE, sizeof(int) * 1000, IPC_CREAT | 0666);
    int shmidB = shmget(IPC_PRIVATE, sizeof(int) * 1000, IPC_CREAT | 0666);

    printf("Shared arrays A and B created\n");

    // attaching the shared memory
    int *A = shmat(shmidA, NULL, 0);
    int *B = shmat(shmidB, NULL, 0);

    int *arr[2] = {A, B};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    pthread_t order_threads[3], chaos_thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    // using the same attr again and again
    for (int i = 0; i < 3; i++)
        pthread_create(&order_threads[i], &attr, order_thread_function, (void *)arr);
    pthread_create(&chaos_thread, &attr, chaos_thread_function, (void *)arr);
    for (int i = 0; i < 3; i++)
        pthread_join(order_threads[i], NULL);
    pthread_join(chaos_thread, NULL);

    shmdt(&shmidA);
    shmdt(&shmidB);

    shmctl(shmidA, IPC_RMID, NULL);
    shmctl(shmidB, IPC_RMID, NULL);
    pthread_mutex_destroy(&arrMutex);
    pthread_mutex_destroy(&arrBMutex);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
    return 0;
}