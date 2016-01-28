#ifndef STACK_H
#define STACK_H

struct stackNode {
    int value;
    struct stackNode *prev;
};
typedef struct stackNode stackNode;

struct stack {
    int size;
    stackNode *top;
};

typedef struct stack stack;

void stack_init(stack *const s);
int stack_size(const stack *const s);
int stack_getTop(const stack *const s);
void stack_push(stack *const s, const int d);
int stack_pop(stack *const s);

#endif
