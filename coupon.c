#include <stdio.h>

int a[1000] = {1,};
int b[1000];

int foo() { return 5; }
//static int x = foo();  
//const int c = foo();

int main()
{//return 0;
  const int c = foo();
  printf("");
  return a[0]+b[0];
}