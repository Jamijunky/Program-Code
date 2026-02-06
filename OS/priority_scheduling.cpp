#include <iostream>
using namespace std;

struct Process
{
  int pid;
  int burstTime;
  int priority;
  int waitingTime;
  int turnaroundTime;
};

int main()
{
  int n;
  cout << "Enter number of processes: ";
  cin >> n;

  Process p[n];

  for (int i = 0; i < n; i++)
  {
    p[i].pid = i + 1;
    cout << "\nProcess " << p[i].pid << endl;
    cout << "Burst Time: ";
    cin >> p[i].burstTime;
    cout << "Priority: ";
    cin >> p[i].priority;
  }

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (p[i].priority > p[j].priority)
      {
        swap(p[i], p[j]);
      }
    }
  }

  p[0].waitingTime = 0;
  for(int i=1;i<n;i++){
    p[i].waitingTime=p[i-1].waitingTime+p[i-1].burstTime;
  }

  for (int i = 0; i < n; i++)
  {
    p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
  }

  cout << "\nPID\tBT\tPR\tWT\tTAT\n";
  for (int i = 0; i < n; i++)
  {
    cout << p[i].pid << "\t"
         << p[i].burstTime << "\t"
         << p[i].priority << "\t"
         << p[i].waitingTime << "\t"
         << p[i].turnaroundTime << endl;
  }
}