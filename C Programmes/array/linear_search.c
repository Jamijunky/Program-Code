#include <stdio.h>

int search(int a[], int n, int x)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return -1;
}

int main()
{
  int a[10], x, i, n;
  n = sizeof(a[n]) / sizeof(a[0]);
  printf("no of elements\n");
  scanf("%d", &n);
  printf("enter the elements\n");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("find\n");
  scanf("%d", &x);
  int index = search(a, n, x);
  if (index > -1)
    printf("%d found at %d", x, index + 1);
  else
    printf("%d not found", x);
}