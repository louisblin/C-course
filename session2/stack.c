#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void stack_init(stack *s)
{
    s->size = 0;
    for (int i = 0; i < STACK_MAX; i++) {
        s->data[i] = 0;
    }
}

int stack_size(stack *s)
{
    return s->size;
}

int stack_getTop(stack *s)
{
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return s->data[s->size-1];
}

void stack_push(stack *s, int d)
{
    if (s->size < STACK_MAX) {
        s->data[s->size++] = d;
    }
    else {
        // TODO: handle by expanding the size of data
        fprintf(stderr, "Error: stack full\n");
    }
}

int stack_pop(stack *s)
{
    int d = -1;
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
    }
    else {
        d = s->data[s->size-1];
        s->size--;
    }
    return d;
}
