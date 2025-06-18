#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    t_binary_tree* tree = create_tree();

    printf("----- Menu Binary Tree-----\n");
    printf("create (tree)\n");
    printf("pre\n");
    printf("in\n");
    printf("post\n");
    printf("height (node)\n");
    printf("print\n");
    printf("exit\n");
    printf("-------------------------------\n");

    while (1) {

        printf("->");
        if (!fgets(input, MAX_INPUT, stdin)) break;
        input[strcspn(input, "\n")] = 0; 

        if (strncmp(input, "create ", 7) == 0) {
            destroy_tree(tree);
            tree = create_tree();
            create_from_text(tree, input + 7);

        } else if (strcmp(input, "pre") == 0) {
            pre_order(tree->root);
            printf("\n");

        } else if (strcmp(input, "in") == 0) {
            in_order(tree->root);
            printf("\n");

        } else if (strcmp(input, "post") == 0) {
            post_order(tree->root);
            printf("\n");

        } else if (strncmp(input, "height ", 7) == 0) {
            char c = input[7];
            t_node* n = find_node(tree->root, c);

            if(n){
                printf("Height: %d\n",height(n));
            }else{
                printf("Node not found.\n");
            } 

        } else if (strcmp(input, "print") == 0) {
            print_tree(tree->root, 0);

        } else if (strcmp(input, "exit") == 0) {
            break;

        } else {
            printf("Invalid!\n");
        }
    }

    destroy_tree(tree);
    return 0;
}