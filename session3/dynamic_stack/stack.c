#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack *const stack_init()
{
    stack *s = (stack*) malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;

    return s;
}

int stack_size(const stack *const s)
{
    return s->size;
}

int stack_getTop(const stack *const s)
{
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return s->top->data;
}

void stack_push(stack *const s, const int d)
{
    stack_node* node = (stack_node*) malloc(sizeof(stack_node));
    node->data = d;
    node->prev = s->top;
    
    // insert node
    s->top = node;
    
    s->size++;
}

int stack_pop(stack *const s)
{
    if (s->size == 0) {
        fprintf(stderr, "Error: stack empty\n");
        return -1;
    }
    
    stack_node* nodeOut = s->top;
    
    s->top = nodeOut->prev;
    s->size--;
    
    int d = nodeOut->data;
    free(nodeOut);
    return d;
}

void stack_dump(const stack *const s) {

    stack_node *node = s->top;

    printf("\t[");
    while (node != NULL) {
    
        printf(" (%d) ->", node->data);
        node = node->prev;
    }
    printf(" NULL ]");
}
