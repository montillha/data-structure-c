#ifndef STACK_H
#define STACK_H

typedef struct {
    int start;
    int end;
} t_interval;

typedef struct {
    int max;
    int top;
    t_interval* items;
} t_stack;

t_stack* create(int max);
void push(t_stack* stack, t_interval value);
t_interval pop(t_stack* stack);
int is_empty(t_stack* stack);
void destroy(t_stack* stack);

#endif
