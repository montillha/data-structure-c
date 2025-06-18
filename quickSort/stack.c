#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

t_stack* create(int max) {
    t_stack* stack = malloc(sizeof(t_stack));
    stack->max = max;
    stack->top = -1;
    stack->items = malloc(sizeof(t_interval) * max);
    return stack;
}

int is_empty(t_stack* stack) {
    return stack->top == -1;
}

int push(t_stack* stack, t_interval value) {
    if (stack->top == stack->max - 1) {
       return 0; 
    }
    stack->items[++stack->top] = value;
    return 1; 
}

int pop(t_stack* stack, t_interval* out) {
    if (is_empty(stack)) {
       return 0; 
    }
    *out = stack->items[stack->top--];
    return 1; 
}

void destroy(t_stack* stack) {
    free(stack->items);
    free(stack);
}
