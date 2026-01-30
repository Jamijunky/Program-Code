#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> at(n), bt(n), rt(n), ct(n), tat(n), wt(n);

    cout << "Enter arrival times:\n";
    for (int i = 0; i < n; i++)
        cin >> at[i];

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
        rt[i] = bt[i];
    }

    cout << "Enter time quantum: ";
    cin >> tq;

    queue<int> q;
    vector<bool> inQueue(n, false);

    int time = 0, completed = 0;
    q.push(0);
    inQueue[0] = true;

    while (completed < n)
    {
        if (q.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (rt[i] > 0)
                {
                    q.push(i);
                    inQueue[i] = true;
                    time = at[i];
                    break;
                }
            }
        }
        int p = q.front();
        q.pop();
        int exec = min(tq, rt[p]);
        rt[p] -= exec;
        time += exec;
        for (int i = 0; i < n; i++)
        {
            if (!inQueue[i] && at[i] <= time && rt[i] > 0)
            {
                q.push(i);
                inQueue[i] = true;
            }
        }
        if (rt[p] > 0)
        {
            q.push(p);
        }
        else
        {
            completed++;
            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
        }
    }
        cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
        for (int i = 0; i < n; i++)
        {
            cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
        }
    
        return 0;
    }
