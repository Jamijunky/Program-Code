#include <iostream>
#include <vector>

using namespace std;

int func(vector<int> &vec, int low, int high)
{
  int i = low, j = high;
  int pivot = vec[low];
  int index=0;
  while (i <= j)
  {
    if (vec[i] >= pivot)
    {
      if (vec[j] < pivot)
      {
        swap(vec[i], vec[j]);
      }
      else
      {
        j--;
      }
    }
    else
    {
      i++;
    }
    index=i;
  }
  return index;
}


void quicksort(vector<int> &vec, int low, int high)
{
  if (low < high)
  {
    int Pindex = func(vec, low, high);
    quicksort(vec, low, Pindex - 1);
    quicksort(vec, Pindex + 1, high);
  }

}


int main()
{
  vector<int> vec;
  int num;        
  while (cin >> num)
  {
    vec.push_back(num);
  }
  int low = 0;
  int high =vec.size() - 1;
  quicksort(vec, low, high);

  for (int v : vec)
  {
    cout << v << " ";
  }
  return 0;
}