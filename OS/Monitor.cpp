#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Monitor {

private:
    mutex mtx;
    condition_variable cv;
    bool busy = false;

public:

    void enter(int id) {

        unique_lock<mutex> lock(mtx);

        while (busy) {
            cv.wait(lock);
        }

        busy = true;

        cout << "Thread " << id << " entered Monitor\n";
    }

    void exit(int id) {

        unique_lock<mutex> lock(mtx);

        cout << "Thread " << id << " leaving Monitor\n";

        busy = false;
        cv.notify_one();
    }
};

Monitor m;

void process(int id) {

    m.enter(id);

    // Critical Section
    this_thread::sleep_for(chrono::seconds(2));

    m.exit(id);
}

int main() {

    thread t1(process, 1);
    thread t2(process, 2);
    thread t3(process, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}