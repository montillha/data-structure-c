#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int *numbers, int start, int end) {
    int pivot = numbers[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swap(&numbers[i], &numbers[j]);
        }
    }
    swap(&numbers[i + 1], &numbers[end]);
    return i + 1;
}

void quicksort_iterative(int numbers[], int n) {
    t_stack* stack = create(n);

    if (!stack){
        return;
    }     
    t_interval initial = {0, n - 1};

    if (!push(stack, initial)) {
        destroy(stack);
        return; 
    }

    while (!is_empty(stack)) {

        t_interval current;
        if (!pop(stack, &current)){
            break;
        }   

        int start = current.start;
        int end = current.end;

        if (start < end) {
            int p = partition(numbers, start, end);

            int left_size = p - 1 - start;
            int right_size = end - (p + 1);

            if (left_size > right_size) {
                if (start < p - 1) {
                    if (!push(stack, (t_interval){start, p - 1})){

                        break; 
                    }    
                }
                if (p + 1 < end) {
                    if (!push(stack, (t_interval){p + 1, end})){ 
                        break;  
                    }
                }
            } else {
                if (p + 1 < end) {
                    if (!push(stack, (t_interval){p + 1, end})) {
                        break;    
                    }
                }
                if (start < p - 1) {
                    if (!push(stack, (t_interval){start, p - 1})) {
                        break;  
                    }
                }
            }
        }
    }

    destroy(stack);
}
int main() {
    int n;
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    quicksort_iterative(numbers, n);

    for (int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    return 0;
}

