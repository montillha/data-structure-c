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
t_stack* create(int);
int push(t_stack*, t_interval);
int pop(t_stack*,t_interval*);
int is_empty(t_stack* );
void destroy(t_stack*);

#endif
