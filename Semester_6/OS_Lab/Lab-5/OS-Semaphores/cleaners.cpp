void *cleaner_runner(void *args) {
    int clean_time;
    room *room_ptr;
    int semValue;
    while (1) {
        sem_wait(&cleaning);    // printf("locked-clean\n"); fflush(stdout);

        // for updating room details
        sem_wait(&setMutex);

        // printf("locked-set\n"); fflush(stdout);

        std::set<room *, decltype(&comp)>::iterator room_set_ptr = room_set.end();
        room_set_ptr--;

        room_ptr = *room_set_ptr;

        // if there are no guests
        if (room_ptr->stay_count == 0) {
            // if (sem_getvalue(&cleaning, &semValue) == 1)
            // {
            sem_post(&setMutex);    // printf("unlock-set\n"); fflush(stdout);
            // sem_wait(&cleaning);
            while (1) {    // wait for all guests to leave
                sem_getvalue(&roomSemaphore, &semValue);
                if (semValue == N)
                    break;
            }
            sem_post(&not_cleaning);
            continue;
        }

        printf("Cleaning room %d\n", room_ptr->room_no);
        fflush(stdout);
        room_set.erase(room_set_ptr);

        clean_time = room_ptr->stay_time;    // cleaning time is proportional to the stay time of the guests
        room_ptr->guest_priority = 0;
        room_ptr->guest_id = 0;
        room_ptr->stay_count = 0;
        room_ptr->stay_time = 0;

        room_set.insert(room_ptr);

        sem_post(&setMutex);    // printf("unlock-set\n"); fflush(stdout);

        sem_post(&cleaning);         // printf("unlock-clean\n"); fflush(stdout);
        sem_wait(&roomSemaphore);    // finished update
        sleep(clean_time);
        printf("Cleaned room %d\n", room_ptr->room_no);
        fflush(stdout);
        sem_post(&roomSemaphore);

        // printf("Sema post\n"); fflush(stdout);
    }
    pthread_exit(NULL);
}