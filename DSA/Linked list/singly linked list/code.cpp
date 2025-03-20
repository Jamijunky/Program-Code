#include <iostream>

using namespace std;

struct node
{
  int data;
  node *next;
  node(int x)
  {
    data = x;
    next = NULL;
  }
  node()
  {
    cout << "Enter value: ";
    int a;
    cin >> a;
    data = a;
    next = NULL;
  };
};

int singlylist(node *curr)
{
  if (curr == NULL)
  {
    return 0;
  }
  cout << curr->data << " ";
  curr = curr->next;
  singlylist(curr);
  return 0;
}

int position_data(node *curr, int position, int count)
{

  if (curr == NULL)
  {
    cout << "\nEither list is empty or Position is not in list\n";
    return -1;
  }
  if (count == position)
  {
    cout << "\nPosition data: " << curr->data << endl;
    return 0;
  }
  position_data(curr->next, position, ++count);
  return 0;
}

int main()
{
  node *head = new node(1);
  node *second = new node(2);
  node *insert = new node; // had to write node(){}; for this in struct
  node *third = new node(3);
  node *fourth = new node; // had to write node(){}; for this in struct

  int position;
  cout << "Enter position: ";
  cin >> position;

  head->next = second;
  second->next = insert;
  insert->next = third;
  third->next = fourth;

  singlylist(head);
  position_data(head, position, 0);

  return 0;
}