void *guest_runner(void *args) {
    // args[0] = priority, args[1] = guest id
    int *input = (int *)args;
    int priority = input[0], guest_id = input[1];
    int stay_time, roomNo, emptyRooms;
    room *r;
    fflush(stdout);
    while (1) {
        // wait for cleaning to finish
        sem_wait(&not_cleaning);
        sem_wait(&setMutex);
        // get the number of empty rooms
        sem_getvalue(&roomSemaphore, &emptyRooms);

        // if there is no empty room, check if someone can be replaced
        if (emptyRooms == 0) {
            r = *room_set.begin();
            if (r->stay_count == 1 && r->guest_priority < priority)    // if the guest in the room has lower priority
            {                                                          // remove the guest to be replaced
                room_set.erase(room_set.begin());
                sem_post(&setMutex);
                printf("Guest %d with priority %d will replace guest %d with priority %d in room %d\n", guest_id, priority, r->guest_id, r->guest_priority, r->room_no);
                fflush(stdout);
                pthread_kill(guests[r->guest_id - 1], SIGALRM);
                r->guest_id = 0;
                r->guest_priority = 0;    // indicates no guest
                room_set.insert(r);
            } else {    // no one can be replaced
                // printf("Guest %d with priority %d is denied room\n", guest_id, priority);
                sem_post(&setMutex);
                sem_post(&not_cleaning);
                // sleep(10+rand()%11);
                continue;
            }
        } else {    // there is an empty room
            sem_post(&setMutex);
        }

        // occupy a room
        sem_wait(&roomSemaphore);
        sem_wait(&setMutex);
        r = *room_set.begin();    // get the room with the lowest stay count
        room_set.erase(room_set.begin());

        printf("Guest %d priority %d occupied room %d\n", guest_id, priority, r->room_no);
        fflush(stdout);

        // insert new room details
        r->guest_priority = priority;
        r->stay_count++;
        stay_time = (rand() % 21) + 10;
        r->stay_time += stay_time;
        r->guest_id = guest_id;
        room_set.insert(r);

        // check if this is the last guest
        if ((*room_set.begin())->stay_count == 2) {
            printf("All rooms occupied twice\nCLEANING WILL START NOW....\n");
            fflush(stdout);
            sem_post(&setMutex);
            // wake up all guests staying in the rooms
            for (pthread_t &thread_id : guests) {
                pthread_kill(thread_id, SIGALRM);
            }
            sem_post(&roomSemaphore);
            printf("Guest %d with priority %d is leaving room %d\n", guest_id, priority, r->room_no);
            fflush(stdout);
            while (1) {    // wait for guests to leave
                sem_getvalue(&roomSemaphore, &emptyRooms);
                if (emptyRooms == N)
                    break;
            }
            // cleaning starts
            sem_post(&cleaning);
            continue;
        }

        sem_post(&setMutex);
        sem_post(&not_cleaning);

        // sleep for a random time(to simulate stay time)
        sleep(stay_time);

        // leave the room
        sem_wait(&setMutex);
        room_set.erase(r);
        r->guest_id = 0;
        r->guest_priority = 0;    // indicates no guest
        room_set.insert(r);

        // if room is occupied by only one guest, then it is available
        // if (r->stay_count <= 1)
        sem_post(&roomSemaphore);
        printf("Guest %d with priority %d is leaving room %d\n", guest_id, priority, r->room_no);
        fflush(stdout);
        sem_post(&setMutex);
    }
    pthread_exit(NULL);
}