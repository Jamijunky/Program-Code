#include <stdio.h>
#include <string.h>

union Data
{
  int i;
  float f;
  char str[4];
};

int main()
{
  union Data data;

  data.i = 10;
  printf("Integer Value: %d\n", data.i);
      data.f = 220.5;
  printf("Float Value: %.2f\n", data.f);
  strncpy(data.str, "Hi", sizeof(data.str) - 1);
  data.str[sizeof(data.str) - 1] = '\0';
  printf("String Value: %s\n", data.str);

  return 0;
}