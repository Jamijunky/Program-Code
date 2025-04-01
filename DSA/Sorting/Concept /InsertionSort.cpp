#include <iostream>
#include <vector>

using namespace std;
void insertionSort(vector<int> &vec)
{
  for (int i = 1; i < vec.size(); i++)
  {
    int k = i;
    for (int j = i - 1; j >= 0; j--)
    {
      if (vec[k] < vec[j])
      {
        swap(vec[k], vec[j]);
        k--;
      }
      else
      {
        break;
      }
    }
  }
}

int main()
{
  vector<int> vec;
  int num;
  cout << "Enter the Numbers\nEnter anything else to come out of input loop\n";
  while (cin >> num)
  {
    vec.push_back(num);
  }
  insertionSort(vec);
  for (int num : vec)
  {
    cout << num << " ";
  }
  return 0;
}