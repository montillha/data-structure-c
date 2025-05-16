
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

t_queue* create(){
    t_queue* queue = malloc(sizeof(t_queue));
    queue->max = MAX_FILA;
    queue->begin =0;
    queue->end=0;
    queue->size=0;
    return queue;

}
void in(t_queue* t_queue,char* cliente){
    if (is_full(t_queue)) {
        return;
    }
    strcpy(t_queue->items[t_queue->end],cliente);
    int next =(t_queue->end + 1) %  t_queue->max;   
    t_queue->end = next;
    t_queue->size++;
}
int out(t_queue* t_queue,char* cliente_out){
   if(is_empty(t_queue)){
        return 0;
    }
    strcpy(cliente_out, t_queue->items[t_queue->begin]); 
    t_queue->begin = (t_queue->begin+1)%t_queue->max;  
    t_queue->size--; 
    return 1;

}
int is_empty(t_queue* t_queue){
    return t_queue->size==0;
}
int is_full(t_queue* t_queue){
    return t_queue->size==t_queue->max;
}
