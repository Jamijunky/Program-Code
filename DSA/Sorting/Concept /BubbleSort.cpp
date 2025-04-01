#include <iostream>
#include <vector>

using namespace std;
void bubbleSort(vector<int> &vec)
{ int n=vec.size();
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
      swapped = false;
      for (int j = 0; j < n - i - 1; j++) {
          if (vec[j] > vec[j + 1]) {
              swap(vec[j], vec[j + 1]);
              swapped = true;
          }
        }
      if (!swapped)
          break;
  }
}



int main()
{
  vector<int> vec;
  int num;
  cout << "Enter the Array\nInput anything except number to come out of input loop\n";
  while (cin >> num)
  {
    vec.push_back(num);
  }
  bubbleSort(vec);
  for (int num : vec)
  {
    cout << num << " ";
  }
  return 0;
}