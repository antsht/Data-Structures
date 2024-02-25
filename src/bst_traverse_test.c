#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_infix_test_1();
void bst_prefix_test_2();
void bst_postfix_test_3();

int main(void) {
    bst_infix_test_1();
    bst_prefix_test_2();
    bst_postfix_test_3();
    return 0;
}

void bst_infix_test_1() {
    t_btree *root = bstree_create_node(10);
    bstree_insert(root, 15, &comp_leafs);
    bstree_insert(root, 5, &comp_leafs);
    bstree_insert(root, 12, &comp_leafs);
    bstree_insert(root, 14, &comp_leafs);
    bstree_insert(root, 2, &comp_leafs);
    bstree_insert(root, 7, &comp_leafs);

    printf("Test 1: Create BST with values 10 15 5 12 14 2 7 \n Print infix...\nTest result: ");
    bstree_apply_infix(root, &applyf);
    printf("SUCCES\n");

    bstree_free(root);
}

void bst_prefix_test_2() {
    t_btree *root = bstree_create_node(10);
    bstree_insert(root, 15, &comp_leafs);
    bstree_insert(root, 5, &comp_leafs);
    bstree_insert(root, 12, &comp_leafs);
    bstree_insert(root, 14, &comp_leafs);
    bstree_insert(root, 2, &comp_leafs);
    bstree_insert(root, 7, &comp_leafs);

    printf("Test 2: Create BST with values 10 15 5 12 14 2 7 \n Print prefix...\nTest result: ");
    bstree_apply_prefix(root, &applyf);
    printf("SUCCES\n");

    bstree_free(root);
}

void bst_postfix_test_3() {
    t_btree *root = bstree_create_node(10);
    bstree_insert(root, 15, &comp_leafs);
    bstree_insert(root, 5, &comp_leafs);
    bstree_insert(root, 12, &comp_leafs);
    bstree_insert(root, 14, &comp_leafs);
    bstree_insert(root, 2, &comp_leafs);
    bstree_insert(root, 7, &comp_leafs);

    printf("Test 3: Create BST with values 10 15 5 12 14 2 7 \n Print postfix...\nTest result: ");
    bstree_apply_postfix(root, &applyf);
    printf("SUCCES\n");

    bstree_free(root);
}