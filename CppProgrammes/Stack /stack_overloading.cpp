#include <iostream>
#include <vector>

using namespace std;

int stack_input(vector<int> &stack, int &top)
{
  cout << "Enter an integer to push: ";
  int x;
  cin >> x;
  stack.push_back(x);
  top++;
  return 0;
}

int remove_element(vector<int> &stack, int &top)
{
  if (top == -1)
  {
    cout << "Stack is empty\n";
    return 0;
  }
  cout << "Popped element is " << stack[top--] << endl;
  return 0;
}
int display(vector<int> &stack, int &top)
{
  if (top == -1)
  {
    cout << "Stack is empty\n";
    return 0;
  }
  cout << "Stack elements are:[ ";
  for (int i = top; i >= 0; i--)
  {
    cout << stack[i] << " ";
  }
  cout << "]" << endl;
  return 0;
}

int main()
{
  int top = -1;
  vector<int> stack;
  int option;
  do
  {
    cout << "\n-------Stack Operations-------\n";
    cout << "Choose the option\n";
    cout << "1. Stack Input\n";
    cout << "2. Removing an Element\n";
    cout << "3. Display\n";
    cout << "4. Exit\n";
    cin >> option;
    switch (option)
    {
    case 1:
      stack_input(stack, top);
      break;
    case 2:
      remove_element(stack, top);
      break;
    case 3:
      display(stack, top);
      break;
    case 4:
      cout << "Exiting......\nExited";
      exit(0);
    default:
      cout << "Choose from the given options only\n";
    }
  } while (option != 4);

  return 0;
}