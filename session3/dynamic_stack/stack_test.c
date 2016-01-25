#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

int main(void) {

    stack *s = stack_init();

    for(int i = 0; i < 5; i++) {
        stack_push(s, i);
        printf("\nPushed on stack(%d) %d :: ", stack_size(s), i);
        stack_dump(s);
    }

    printf("\n\nTop is (%d) %d\n", stack_size(s), stack_getTop(s));

    for(int i = 0; i < 5; i++) {
        int d = stack_pop(s);
        printf("\nPopped from stack(%d) %d :: ", stack_size(s), d);
        stack_dump(s);
    }

    printf("\n\nPopping empty stack...");
    printf("(%d) %d :: ", stack_size(s), stack_pop(s));
    stack_dump(s);

    free(s);
    return 0;
}
