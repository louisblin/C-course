#ifndef STACK_H
#define STACK_H

#define STACK_MAX 100

struct stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct stack stack;

void stack_init(stack *s);
int stack_size(stack *s);
int stack_getTop(stack *s);
void stack_push(stack *s, int d);
int stack_pop(stack *s);

#endif
