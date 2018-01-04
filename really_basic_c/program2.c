/*
Drawn from stuff in https://fresh2refresh.com/c-programming/c-basic-program/

compile with: gcc program2.c -o program2
execute with: ./program2 1 2 3
cleanup with: rm program2

*/

#include <stdio.h>
#include <stdlib.h>

int i;
int total = 0;

/*
The main function can either take in no arguments, or these two.
argc is an integer that gives the number of arguments (that is, the length of argv)
argv is an array of strings that are the command-line arguments provided.  argv[0] is the executable name itself, such as "./program2"
*/
int main(int argc, char *argv[]) {
  for (i = 1; i < argc; i++) {
    /* atoi seems to return 0 for non-integers, so this just ignores them. */
    total += atoi (argv[i]);
  }
  printf ("Sum of all_arguments : %d \n", total);
  return 0;
}
