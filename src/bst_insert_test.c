#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

void bst_insert_test_1();
void bst_insert_test_2();

int main(void) {
    bst_insert_test_1();
    bst_insert_test_2();
    return 0;
}

void bst_insert_test_1() {
    t_btree *root = bstree_create_node(10);
    t_btree *r_leaf = bstree_create_node(15);
    t_btree *l_leaf = bstree_create_node(5);
    root->right = r_leaf;
    root->left = l_leaf;

    bstree_insert(root, 12, &comp_leafs);

    printf(
        "Test 1: Create BST with root 10, r_leaf 15 and l_leaf 5. \nInsert value 12 to BST. \n Node with 12 "
        "should become left leaf of node with value 15. \nTest result: ");
    int checking_test1 = 1;
    if (!(root->item == 10)) checking_test1 = 0;
    if (!(root->right == r_leaf)) checking_test1 = 0;
    if (!(root->left == l_leaf)) checking_test1 = 0;
    if (!(r_leaf->item == 15)) checking_test1 = 0;
    if (!(r_leaf->right == NULL)) checking_test1 = 0;
    if (!(r_leaf->left->item == 12)) checking_test1 = 0;
    if (!(l_leaf->item == 5)) checking_test1 = 0;
    if (!(l_leaf->right == NULL)) checking_test1 = 0;
    if (!(l_leaf->left == NULL)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");

    free(r_leaf->left);
    free(l_leaf);
    free(r_leaf);
    free(root);
}

void bst_insert_test_2() {
    t_btree *root = bstree_create_node(10);
    t_btree *r_leaf = bstree_create_node(15);
    t_btree *l_leaf = bstree_create_node(5);
    root->right = r_leaf;
    root->left = l_leaf;

    bstree_insert(root, 15, &comp_leafs);

    printf(
        "Test 2: Try to insert a node wiht existing value. \n Should scan the tree and pass. "
        "\nTest result: ");
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