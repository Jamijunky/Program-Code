#include <iostream>
 #include <vector> 
 using namespace std;
struct Process
{
  int pid;
  int burstTime;
  int waitingTime;
  int turnaroundTime;
  int completionTime;
};
int main()
{
  int n;
  int contextSwitch;
  cout << "Enter number of processes: ";
  cin >> n;
  cout << "Enter context switching time: ";
  cin >> contextSwitch;
  vector<Process> p(n);
  for (int i = 0; i < n; i++)
  {
    p[i].pid = i + 1;
    cout << "Enter burst time for process P" << p[i].pid << ": ";
    cin >> p[i].burstTime;
  }
  int currentTime = 0;
  for (int i = 0; i < n; i++)
  {
    p[i].waitingTime = currentTime;
    currentTime += p[i].burstTime;
    p[i].completionTime = currentTime;
    p[i].turnaroundTime = p[i].completionTime;
    if (i != n - 1)
    {
      currentTime += contextSwitch;
    }
  }
  cout << "\nPID\tBurst\twaiting\t  Turnaround\tCompletion\n";
  for (int i = 0; i < n; i++)
  {
    cout << "P" << p[i].pid << "\t  " << p[i].burstTime << "\t   " << p[i].waitingTime << "\t      " << p[i].turnaroundTime << "\t\t      " << p[i].completionTime << endl;
  }
  float avgWT = 0, avgTAT = 0;
  for (int i = 0; i < n; i++)
  {
    avgWT += p[i].waitingTime;
    avgTAT += p[i].turnaroundTime;
  }
  cout << "\nAverage Waiting Time = " << avgWT / n << endl;
  cout << "\nAverage Turnaround Time = " << avgTAT / n << endl<<endl;
  return 0;
}