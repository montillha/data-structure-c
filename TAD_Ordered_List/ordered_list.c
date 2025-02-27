#include <stdio.h>
#include <stdlib.h>
#include "ordered_list.h"
t_ordered_list* create_ordered_list(int max){
    t_ordered_list* ordered_list=(t_ordered_list*)malloc(sizeof(t_ordered_list));
    ordered_list->items=(int*)malloc(sizeof(int)*max);
    ordered_list->n=0;
    ordered_list->max=max;
    return ordered_list;
}

int size(t_ordered_list* list){
    return list->n;
}

int is_empty(t_ordered_list* list){
    return size(list) <= 0;
}

int is_full(t_ordered_list* list){
    return size(list) >= list->max;
}

void destroy(t_ordered_list* list){
    free(list->items);
    free(list);
}

void clear(t_ordered_list* list){
    list->n=0;
}
t_ordered_list* reallocate_list(t_ordered_list* list){
    return (t_ordered_list *)realloc(list, list->max/2 * sizeof(int));

}
int insert(t_ordered_list* list, int value){
    if(list->n+1 >= list->max){
        list->items = realloc(list->items, list->max/2 * sizeof(int));
        list->max+=(list->max/2);
       
    }

    if( (value >= list->items[size(list)-1]) ||is_empty(list)){
        list->items[list->n++]=value;
        return 1;
 
    }
    
    int index_insert=size(list);
    for(int i=size(list)-1;i>=0;i--){
        if(value<list->items[i]){
            list->items[i+1]=list->items[i];
          
            index_insert--;
        }
    }
    list->items[index_insert]=value;
    list->n++;
    return 1;
}

int search(t_ordered_list* list, int value){
    if(is_empty(list)) return -1;
    for(int i = 0; i <size(list); i++){
        if(list->items[i]==value) return i;
    }
    return -1;
    
}
int remove_by_index(t_ordered_list* list, int index){
    if(is_empty(list) || index >=size(list)) return 0;
    for(int i=index;i<size(list)-1;i++){
        list->items[i]=list->items[i+1];
            
    }
    list->n--;
    return 1;
    
}

int remove_by_value(t_ordered_list* list, int value){
    if(is_empty(list)) return 0;
    if(search(list,value)==-1) return 0;
    for(int i=search(list,value);i<size(list)-1;i++){
        list->items[i]=list->items[i+1];

    }
    list->n--;
    return 1;

}

int remove_end(t_ordered_list* list){
    list->n--;
    return 1;
}

void print_ordered_list(t_ordered_list* list){
    for (int i = 0; i < size(list); i++){
        printf("%d ",list->items[i]);
    }
    printf("\n");
    
}

t_ordered_list* merge(t_ordered_list* list1, t_ordered_list* list2){
    t_ordered_list* list3=create_ordered_list(list1->max+list2->max);
    int index_list1=0;
    int index_list2=0;
    while(index_list1 < size(list1) && index_list2 < size(list2)){
        if(list1->items[index_list1] < list2->items[index_list2]){
            list3->items[list3->n++] = list1->items[index_list1++];
        }else{
            list3->items[list3->n++] = list2->items[index_list2++];
        }
    }

    while(index_list1 < size(list1)){
        list3->items[list3->n++] = list1->items[index_list1++];
    }
    while(index_list2 < size(list2)){
        list3->items[list3->n++] = list2->items[index_list2++];
    }
    return list3;
    
}