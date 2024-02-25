#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_create_test_1();
void bst_create_test_2();

int main(void) {
    bst_create_test_1();
    bst_create_test_2();
    return 0;
}

void bst_create_test_1() {
    t_btree *root = bstree_create_node(10);

    printf("Test 1: Create a root node for BST. Put value 10 inside. \nTest result: ");
    int checking_test1 = 1;
    if (!(root->item == 10)) checking_test1 = 0;
    if (!(root->right == NULL)) checking_test1 = 0;
    if (!(root->left == NULL)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    free(root);
}

void bst_create_test_2() {
    t_btree *root = bstree_create_node(10);
    t_btree *r_leaf = bstree_create_node(15);
    t_btree *l_leaf = bstree_create_node(5);
    root->right = r_leaf;
    root->left = l_leaf;

    printf(
        "Test 2: Create a root node for BST. Put value 10 inside.\n- Create to leaf nodes with values 5 and "
        "15.\n- Attach leafs to the root. \nTest result: ");
    int checking_test1 = 1;
    if (!(root->item == 10)) checking_test1 = 0;
    if (!(root->right == r_leaf)) checking_test1 = 0;
    if (!(root->left == l_leaf)) checking_test1 = 0;
    if (!(r_leaf->item == 15)) checking_test1 = 0;
    if (!(r_leaf->right == NULL)) checking_test1 = 0;
    if (!(r_leaf->left == NULL)) checking_test1 = 0;
    if (!(l_leaf->item == 5)) checking_test1 = 0;
    if (!(l_leaf->right == NULL)) checking_test1 = 0;
    if (!(l_leaf->left == NULL)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    free(l_leaf);
    free(r_leaf);
    free(root);
}