#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

t_binary_tree* create_tree() {
    t_binary_tree* tree = malloc(sizeof(t_binary_tree));
    tree->root = NULL;
    return tree;
}

void destroy_node(t_node* node) {
    if (!node){
        return;
    }    
    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
}

void destroy_tree(t_binary_tree* tree) {
    destroy_node(tree->root);
    free(tree);
}

int is_valid(char* text) {
    int count = 0;
    for (int i = 0; text[i]; i++) {
        if (text[i] == '('){
            count++;
        }    
        else if (text[i] == ')'){
            count--;
        }    
        if (count < 0){
            return 0;
        }    
    }
    return count == 0;
}

t_node* parse_node(char** str) {

    while(**str == ' '){
        (*str)++;
    }    

    if (**str == '\0' || **str == ')'){
        return NULL;
    }

    t_node* node = malloc(sizeof(t_node));
    node->value = **str;
    node->left = node->right = NULL;
    (*str)++;

    while (**str != '('){
        (*str)++;
    }    
    (*str)++; node->left = parse_node(str);

    while (**str != '('){
        (*str)++;
    }
    (*str)++; 

    node->right = parse_node(str);
    while (**str != ')'){
        (*str)++;
    }    
    (*str)++;

    return node;
}

void create_from_text(t_binary_tree* tree, char* text) {
    if (!is_valid(text)) {
        printf("invalid\n");
        return;
    }
    char* ptr = text;
    while (*ptr != '('){
        ptr++;
    }    
    ptr++;
    tree->root = parse_node(&ptr);
}

void pre_order(t_node* node){
    if(node !=NULL){
        printf("%c ",node->value);
        pre_order(node->left);
        pre_order(node->right);
    }

}
void in_order(t_node* node){
    if(node !=NULL){
        in_order(node->left);
        printf("%c ",node->value);
        in_order(node->right);
    }


}
void post_order(t_node* node){
    if(node !=NULL){
        post_order(node->left);
        post_order(node->right);
        printf("%c ",node->value);
    }

}

int height(t_node* node) {
    if (!node){
        return -1;
    }    
    int h_left = height(node->left);
    int h_right = height(node->right);
    if(h_left>h_right){
        return h_left+1;
    }
    return h_right+1;
}

void print_tree(t_node* node, int depth) {
    if (!node){
        return;
    }    
    print_tree(node->right, depth + 1);
    for (int i = 0; i < depth; i++){
        printf("   ");
    }    
    printf("%c\n", node->value);
    print_tree(node->left, depth + 1);
}
t_node* find_node(t_node* node, char value) {
    if (!node) return NULL;
    if (node->value == value) return node;
    t_node* found = find_node(node->left, value);
    if (found) return found;
    return find_node(node->right, value);
}

