#ifndef STACK_H
#define STACK_H

typedef struct stack_node_t {

    int data;

    struct stack_node_t* prev;

} stack_node;

typedef struct stack_t {

    int size;

    stack_node* top;

} stack;

stack *const stack_init();
int stack_size(const stack *const s);
int stack_getTop(const stack *const s);
void stack_push(stack *const s, const int d);
int stack_pop(stack *const s);
void stack_dump(const stack *const s);

#endif /* STACK_H */
