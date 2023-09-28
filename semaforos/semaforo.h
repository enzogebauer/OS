#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void incrementa(int *p){
  int a;
  a = *p;
  a++;
  Sleep(100);
  *p = a;
printf("a = %d\n", a);
}

void decrementa(int *p){
 int a;
  a = *p;
  a--;
  Sleep(100);
  *p = a;
  printf("a = %d\n", a);	
}
