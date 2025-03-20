#include <stdio.h>
struct time
{
  int hours;
  int minutes;
  int seconds;
};
int main()
{
  struct time *ptr1, t1;
  ptr1 = &t1;
  struct time *ptr2, t2;
  ptr2 = &t2;

  printf("enter hour: ");
  scanf("%d", &ptr1->hours);
  printf("enter minute: ");
  scanf("%d", &ptr1->minutes);
  printf("enter second: ");
  scanf("%d", &ptr1->seconds);
  printf("Enter the second time in 24-hour format (HH:MM:SS): %d:%d:%d\n", (ptr1)->hours, (ptr1)->minutes, (ptr1)->seconds);

  printf("enter hour: ");
  scanf("%d", &ptr2->hours);
  printf("enter minute: ");
  scanf("%d", &ptr2->minutes);
  printf("enter second: ");
  scanf("%d", &ptr2->seconds);
  printf("Enter the second time in 24-hour format (HH:MM:SS): %d:%d:%d\n", (ptr2)->hours, (ptr2)->minutes, (ptr2->seconds));

  printf("sum is %dhrs : %dmin : %dsec", ptr1->hours + ptr2->hours, ptr1->minutes + ptr2->minutes, ptr1->seconds + ptr2->seconds);

  return 0;
}