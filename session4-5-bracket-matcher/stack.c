#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack* stack_init()
{
    stack *s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;

    return s;
}

int stack_size(const stack *const s)
{
    return s->size;
}

bool stack_is_empty(const stack *const s)
{
    return s->size == 0;
}

int stack_getTop(const stack *const s)
{
    if (s->size == 0) {
        //fprintf(stderr, "Error: stack empty\n");
        return -1;
    }

    return s->top->value;
}

void stack_push(stack *const s, const int d)
{
    stackNode *newNode;
    newNode = (stackNode*) malloc(sizeof(stackNode));
    newNode->value = d;
    newNode->prev = s->top;
    s->top = newNode;

    s->size++;
}

int stack_pop(stack *s)
{
    int d;
    if(s->size < 1){
        //fprintf(stderr, "Something went wrong: \n the stack is empty");
        return -1;
    }

    stackNode* tmpPointer = s->top;
    s->top = s->top->prev;
    s->size--;

    d = tmpPointer->value;

    free(tmpPointer);
    return d;

}

void stack_empty(stack *const s) {

  while (!stack_is_empty(s)) {
    stack_pop(s);
  }
}

