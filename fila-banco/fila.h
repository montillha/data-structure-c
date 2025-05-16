#ifndef FILA_H
#define FILA_H
#define MAX_FILA 20

typedef struct{
    int max;
    int begin;
    int end;
    int size;
    char items[MAX_FILA][25];
}t_queue;

t_queue* create();
void in(t_queue*,char*);
int out(t_queue*,char*);
int is_empty(t_queue*);
int is_full(t_queue*);
int size(t_queue*);

#endif