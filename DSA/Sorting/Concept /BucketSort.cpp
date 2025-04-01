#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<float> &temp)
{
  int n = temp.size();
  for (int i = 1; i < n; i++)
  {
    float key = temp[i];
    int j = i - 1;
    while (j >= 0 && temp[j] > key)
    {
      temp[j + 1] = temp[j];
      j--;
    }
    temp[j + 1] = key;
  }
}
void bucketsort(vector<float> &vec)
{
  int n = vec.size();
  vector<vector<float>> temp(n);
  for (int i = 0; i < vec.size(); i++)
  {
    int b = min(n - 1, static_cast<int>(vec[i] * n));
    temp[b].push_back(vec[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (temp[i].empty())
    {
      continue;
    }
    else
    {
      insertionsort(temp[i]);
    }
  }
  vec.clear();
  for (int i = 0; i < n; i++)
  {
    vec.insert(vec.end(), temp[i].begin(), temp[i].end());
  }
}

int main()
{
  vector<float> vec;
  float num;
  cout << "Enter the Array(can be whole number,decimal number or mixture of both.\nInput anything except number to come out of input loop.\n";
  while (cin >> num)
  {
    vec.push_back(num);
  }
  bucketsort(vec);

  cout << "Sorted Array is: ";
  for (int i = 0; i < vec.size(); i++)
  {
    cout << vec[i] << " ";
  }

  return 0;
}