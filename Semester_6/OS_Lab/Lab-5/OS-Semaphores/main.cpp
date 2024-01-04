#include <limits.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

#include <iostream>
#include <set>
#include <vector>

// declare semaphores:
// roomSemaphore: to keep track of empty rooms
// cleaning/ not_cleaning: binary semaphore(s) to indicate ongoing tasks
// setMutex: to protect the set of rooms
sem_t roomSemaphore, cleaning, not_cleaning, setMutex;

using namespace std;

// room struct to keep track of room details
struct room {
    int room_no;
    int stay_count = 0;
    int stay_time = 0;
    int guest_id;
    int guest_priority = 0;
};

// custom comparator function for the set of rooms
bool comp(const room *a, const room *b) {
    if (a->stay_count == b->stay_count) {
        if (a->guest_priority == b->guest_priority)
            return a < b;
        else
            return a->guest_priority < b->guest_priority;
    }
    return a->stay_count < b->stay_count;
}

// signal handler to wake up a sleeping thread
void signal_handler(int signum) {
    return;
}

// global variables (accessible to all threads)
vector<room> rooms;
vector<pthread_t> guests, cleaners;
set<room *, decltype(&comp)> room_set(&comp);
int Y, N, X;

// cleaners /guest thread runner
#include "cleaners.cpp"
#include "guests.cpp"

int main() {
    // handle SIGALRM
    signal(SIGALRM, signal_handler);
    cout << "Enter Y, N, X: ";
    cin >> Y >> N >> X;

    // initialize semaphores
    sem_init(&cleaning, 0, 0);        // initialized to 0 as not cleaning at the start
    sem_init(&not_cleaning, 0, 1);    // initialized to 1 as not cleaning at the start
    sem_init(&setMutex, 0, 1);        // initialized to 1
    sem_init(&roomSemaphore, 0, N);

    // initialize rooms
    rooms.resize(N);
    for (int i = 0; i < N; ++i) {
        rooms[i].room_no = i + 1;
        room_set.insert(&rooms[i]);
    }

    // declare threads
    guests.resize(Y);
    cleaners.resize(X);

    // create guest threads
    int guestPriority[N];
    int args[Y][2];
    for (int i = 0; i < Y; ++i) {
        guestPriority[i] = (rand() % Y) + 1;
        args[i][0] = guestPriority[i];    // priority
        args[i][1] = i + 1;               // guest id
        pthread_create(&guests[i], NULL, guest_runner, (void *)args[i]);
    }
    // create cleaner threads
    for (int i = 0; i < X; ++i) {
        pthread_create(&cleaners[i], NULL, cleaner_runner, NULL);
    }

    for (int i = 0; i < Y; ++i) {
        pthread_join(guests[i], NULL);
    }

    for (int i = 0; i < X; ++i) {
        pthread_join(cleaners[i], NULL);
    }

    return 0;
}