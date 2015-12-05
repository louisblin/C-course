#include <stdio.h>

#include "pointers.h"

int main (void) {

    int  var = 20;   /* actual variable declaration */
    int *p = &var; 

    printf("1 var is %d\n", var);
    helper(p);
    printf("4 var is %d\n", var);
  
    return 0;
}

void helper(int* p) {

    printf("2 p is %d\n", *p);
    *p = 30;
    printf("3 p is %d\n", *p);
}

/* Notes:
 * 
 * Compile safely
 * gcc -c file.c -Wall -Werror -pedantic -o myExec
 *
 * Compile, and stop after assembly generation
 * gcc -S -c files.c -Wall -Werror -pedantic -o myExec
 *
 * Same, but specifying levels of optimisation [1,2,3]
 * gcc -S -O3 -c file.c
 */
