#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = malloc(sizeof(t_btree));
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int comp_leafs(int a, int b) { return a - b; }

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    if (root != NULL) {
        if (cmpf(item, root->item) == 0) {
            return;
        } else if (cmpf(item, root->item) > 0) {
            if (root->right == NULL)
                root->right = bstree_create_node(item);
            else
                bstree_insert(root->right, item, cmpf);
        } else if (cmpf(item, root->item) < 0) {
            if (root->left == NULL)
                root->left = bstree_create_node(item);
            else
                bstree_insert(root->left, item, cmpf);
        }
    }
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root != NULL) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}

void applyf(int item) { printf("%d - ", item); }

void bstree_free(t_btree *root) {
    if (root != NULL) {
        bstree_free(root->left);
        bstree_free(root->right);
        free(root);
    }
}