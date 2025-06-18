#include <stdio.h>
#include "stack.h"

/*
Estratégia: empilhar a partição maior antes da menor. Dessa forma, a menor fica no topo da pilha para ser processada primeiro,
deixando a pilha com complexidade de espaço  log n).
*/

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

void quicksort_iterative(int numbers[], int n,t_stack* stack) {

    t_interval initial = {0, n - 1};
    push(stack, initial);

    while (!is_empty(stack)) {
        t_interval current = pop(stack);
        int start = current.start;
        int end = current.end;

        if (start < end) {
            int p = partition(numbers, start, end);

            int left_size = p - 1 - start;
            int right_size = end - (p + 1);

            if (left_size > right_size) {
                if (start < p - 1)
                    push(stack, (t_interval){start, p - 1});
                if (p + 1 < end)
                    push(stack, (t_interval){p + 1, end});
            } else {
                if (p + 1 < end)
                    push(stack, (t_interval){p + 1, end});
                if (start < p - 1)
                    push(stack, (t_interval){start, p - 1});
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }
    t_stack* stack = create(n);
    quicksort_iterative(numbers, n,stack);

    for (int i = 0; i < n; i++){
        printf("%d ", numbers[i]);
    }    
    destroy(stack);
    return 0;

}
