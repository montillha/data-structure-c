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

void push(t_stack* stack, t_interval value) {
    if (stack->top == stack->max - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

t_interval pop(t_stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

void destroy(t_stack* stack) {
    free(stack->items);
    free(stack);
}
