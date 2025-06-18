#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct t_node {
    char value;
    struct t_node* left;
    struct t_node* right;
} t_node;

typedef struct {
    t_node* root;
} t_binary_tree;

t_binary_tree* create_tree();
void destroy_tree(t_binary_tree* tree);
void create_from_text(t_binary_tree* tree,char* text);
void pre_order(t_node* node);
void in_order(t_node* node);
void post_order(t_node* node);
int height(t_node* node);
void print_tree(t_node* node, int depth);
int is_valid(char* text);
t_node* find_node(t_node* node, char value);
#endif
