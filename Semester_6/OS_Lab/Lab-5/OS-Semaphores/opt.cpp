void *guest_runner(void *args)
{
    int priority = *(int *)args;
    int stay_time, roomNo;
    int semValue;
    room *r;
    while (1)
    {
        sem_wait(&not_cleaning); // wait until the not_cleaning is posted by the cleaner
        printf("locked-not clean\n");
        fflush(stdout);

        sem_wait(&minMutex); // waiting for the minMutex to be available
        printf("locked-min\n");
        fflush(stdout);
        if (priority <= minPriority) // when the guest priority is the lowest
        {
            minPriority = priority;
            sem_post(&minMutex);
            printf("unlock-min\n");
            fflush(stdout);
            sem_wait(&roomSemaphore); // wait until room is available
            printf("Sema wait\n");
            fflush(stdout);
        }
        else
        {
            sem_post(&minMutex);
            printf("unlock-min\n");
            fflush(stdout);
            sem_getvalue(&roomSemaphore, &semValue);
            if (semValue > 0) // if there is a room available
            {
                sem_wait(&roomSemaphore); // decrement the semaphore
                printf("Sema wait\n");
                fflush(stdout);
            }
            // else we will remove the guest with lowest priority
        }

        sem_wait(&setMutex);
        printf("locked-set\n");
        fflush(stdout);
        r = *room_set.begin(); // accomodate the guest in the first room of the set
        roomNo = r->room_no;
        printf("Guest %d is staying in room %d\n", priority, roomNo);
        fflush(stdout);
        room_set.erase(room_set.begin());
        r->room_no = roomNo;
        r->guest_priority = priority;
        r->stay_count++;
        stay_time = (rand() % 21) + 10;
        r->stay_time += stay_time;
        room_set.insert(r);
        fflush(stdout);

        sem_wait(&minMutex);
        printf("locked-min\n");
        fflush(stdout);
        minPriority = (*room_set.begin())->guest_priority;
        sem_post(&minMutex);
        printf("unlock-min\n");
        fflush(stdout);

        if ((*room_set.begin())->stay_count == 2)
        { // last guest to occupy any room before cleaning

            // sem_wait(&not_cleaning);
            printf("locked-not clean\n");
            fflush(stdout);
            sem_post(&setMutex);
            printf("unlock-cleaning\n");
            fflush(stdout);
            sem_post(&cleaning);
            continue;
        }

        sem_post(&setMutex);
        printf("unlock-set\n");
        fflush(stdout);
        sem_post(&not_cleaning); // post it again to use by other guests
        printf("unlock-not clean\n");
        fflush(stdout);

        sleep(stay_time / 10);

        // guest is leaving
        // set the priority to 0 implying that room is available
        sem_wait(&setMutex);
        printf("locked-set\n");
        fflush(stdout);

        room_set.erase(r);
        r->guest_priority = 0;
        r->room_no = roomNo;
        room_set.insert(r);
        sem_post(&setMutex);
        printf("unlock-set\n");
        fflush(stdout);

        // if room is occupied by only one guest, then it is available
        if (r->stay_count <= 1)
            sem_post(&roomSemaphore);
    }
    pthread_exit(NULL);
}