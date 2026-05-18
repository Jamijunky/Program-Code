#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

#define N 5

sem_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (true) {
        cout << "Philosopher " << id << " is thinking\n";
        sleep(1);

        // Pick up left fork
        sem_wait(&forks[id]);
        cout << "Philosopher " << id << " picked up left fork\n";

        // Pick up right fork
        sem_wait(&forks[(id + 1) % N]);
        cout << "Philosopher " << id << " picked up right fork\n";

        cout << "Philosopher " << id << " is eating\n";
        sleep(1);

        // Put down forks
        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);

        cout << "Philosopher " << id << " put down forks\n";
    }
}

int main() {
    pthread_t philo[N];
    int ids[N];

    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philo[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(philo[i], NULL);

    return 0;
}
