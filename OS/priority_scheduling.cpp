#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id;
    int burstTime;
    int priority;
};

bool compare(Process a, Process b) {
    return a.priority < b.priority; // Lower number = higher priority
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;

        cout << "Enter Burst Time for P" << i + 1 << ": ";
        cin >> p[i].burstTime;

        cout << "Enter Priority for P" << i + 1 << ": ";
        cin >> p[i].priority;
    }

    // Sort by priority
    sort(p.begin(), p.end(), compare);

    vector<int> wt(n), tat(n);

    // Waiting Time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + p[i - 1].burstTime;
    }

    // Turnaround Time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + p[i].burstTime;
    }

    double avgWT = 0, avgTAT = 0;

    cout << "\nProcess\tBT\tPriority\tWT\tTAT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].burstTime << "\t"
             << p[i].priority << "\t\t"
             << wt[i] << "\t"
             << tat[i] << endl;

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    cout << "\nAverage Waiting Time = " << avgWT << endl;
    cout << "Average Turnaround Time = " << avgTAT << endl;

    return 0;
}