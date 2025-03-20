#include <stdio.h>
int binsearch(int w, int x, int y, int z);
int main()
{
  int a[10];
  int x, i, n;
  printf("no of elements");
  scanf("%d", &n);
  printf("enter the elements\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  n = sizeof(a[n]) / sizeof(a[0]);
  printf("no to find\n");
  scanf("%d", &x);
  int index = binsearch(a[], 0, n, x);
}

int binsearch(int a, int l, int r, int x)
{
  if (r >= l)
  {
    int mid = (r + l) / 2;
    if (a[mid] == x)
      return mid;
    if (a[mid] > x)
      return binsearch(a, l, mid - 1, x);
    else
      return binsearch(a, mid + 1, r, x);
    return -1;
  }
}