#include <iostream>   
#include <vector>     
#include <cstdlib>   
#include <ctime>     

using namespace std;
int main()
{
   srand(time(0));
  int noOfProcess = rand() % (100 - 1 + 1) + 1;
  vector<int> processes(noOfProcess);
  vector<int> arrival_Time(noOfProcess);
  vector<int> burst_Time(noOfProcess);
  vector<int> completion_Time(noOfProcess);
  vector<int> turnAround_Time(noOfProcess);
  vector<int> waiting_Time(noOfProcess);

 
  for (int i = 0; i < noOfProcess; i++)
  {
    processes[i] = i + 1;
    arrival_Time[i] = rand() % (10 - 0 + 1) + 0;
    burst_Time[i] = rand() % (20 - 10 + 1) + 10;
    completion_Time[i] = burst_Time[i]+arrival_Time[i] ;
    turnAround_Time[i] = completion_Time[i] - arrival_Time[i];
    waiting_Time[i] = turnAround_Time[i] - burst_Time[i];
  }
  cout<<"| Processes | Arrival Time | Burst Time | Completion Time | Turn Around Time | Waiting Time |\n";
  cout<<"-------------------------------------------------------------\n";
  for(int i=0;i<noOfProcess;i++){
    cout<< "|P" << processes[i]<<"|"<< arrival_Time[i]<<"|"<<burst_Time[i]<<"|"<<completion_Time[i]<<"|"<<turnAround_Time[i]<<"\n";
  }

  return 0;
}