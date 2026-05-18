#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mtx;   // renamed from mutex
pthread_mutex_t wrt;

int readcount = 0;

void* reader(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&mtx);
    readcount++;

    if (readcount == 1)
        pthread_mutex_lock(&wrt);

    pthread_mutex_unlock(&mtx);

    cout << "Reader " << id << " is reading\n";
    sleep(1);

    pthread_mutex_lock(&mtx);
    readcount--;

    if (readcount == 0)
        pthread_mutex_unlock(&wrt);

    pthread_mutex_unlock(&mtx);

    return NULL;
}

void* writer(void* arg) {
    int id = *(int*)arg;

    pthread_mutex_lock(&wrt);

    cout << "Writer " << id << " is writing\n";
    sleep(1);

    pthread_mutex_unlock(&wrt);

    return NULL;
}

int main() {
    pthread_t r[5], w[2];

    pthread_mutex_init(&mtx, NULL);
    pthread_mutex_init(&wrt, NULL);

    int reader_ids[5] = {1, 2, 3, 4, 5};
    int writer_ids[2] = {1, 2};

    for (int i = 0; i < 5; i++)
        pthread_create(&r[i], NULL, reader, &reader_ids[i]);

    for (int i = 0; i < 2; i++)
        pthread_create(&w[i], NULL, writer, &writer_ids[i]);

    for (int i = 0; i < 5; i++)
        pthread_join(r[i], NULL);

    for (int i = 0; i < 2; i++)
        pthread_join(w[i], NULL);

    pthread_mutex_destroy(&mtx);
    pthread_mutex_destroy(&wrt);

    return 0;
}