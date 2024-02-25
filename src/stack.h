#ifndef STACK_H
#define STACK_H

#define NULL ((void *)0)
#define INT_MIN -2147483648

typedef struct stack {
    int value;
    struct stack *next;
} stack;

struct stack *init(int value);
void push(int value, stack *s_root);
int pop(stack *s_root);
void destroy(stack *s_root);

#endif