#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main(void) {

    stack *s = (stack*) malloc(sizeof(stack));
    stack_init(s);

    for(int i = 0; i < 5; i++) {
        stack_push(s, i);
        printf("Pushed on stack(%d) %d\n", stack_size(s), i);
    }

    printf("\nTop is (%d) %d\n\n", stack_size(s), stack_getTop(s));

    for(int i = 0; i < 5; i++) {
        int d = stack_pop(s);
        printf("Popped from stack(%d) %d\n", stack_size(s), d);
    }

    free(s);
    return 0;
}
