/*
Drawn from stuff in https://fresh2refresh.com/c-programming/c-basic-program/

compile with: gcc program3.c -o program3
execute with: ./program3 1 2 3
cleanup with: rm program3

*/

#include <stdio.h> /* used for printf */
#include <stdlib.h> /* used for atoi */

int i;
int total = 0;

int sum (int, int);

int main(int argc, char *argv[]) {
  for (i = 1; i < argc; i++) {
    /* atoi seems to return 0 for non-integers, so this just ignores them. */
    total = sum ( total, atoi (argv[i]));
  }
  printf ("Sum of all_arguments : %d \n", total);
  return 0;
}

int sum (int a, int b)
{
    return a + b;
}
