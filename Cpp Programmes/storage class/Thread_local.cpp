
using namespace std;

// Defining thread-local variable
thread_local int val = 10;

// Mutex for synchronization
mutex mtx;

int main() {
  
    // Created 3 threads
    // Modify value in thread 1
    thread th1([]() {
        val += 18;
        lock_guard<mutex> lock(mtx);
        cout << "Thread 1 value: " << val << '\n';
    });

    thread th2([]() {
      
        // Modify value in thread 2
        val += 7;
        lock_guard<mutex> lock(mtx);
        cout << "Thread 2 value: " << val << '\n';
    });

    thread th3([]() {
      
        // Modify value in thread 3
        val += 13;
        lock_guard<mutex> lock(mtx);
        cout << "Thread 3 value: " << val << '\n';
    });

    // Wait for all threads to finish
    th1.join();
    th2.join();
    th3.join();

    // Print the value of value in the main thread
    cout << "Main thread value: " << val << '\n';

    return 0;
}
