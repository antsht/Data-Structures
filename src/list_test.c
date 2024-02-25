#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void init_test1();
void add_data_test1();
void add_data_test2();
void find_data_test1();
void remove_data_test1();
void remove_data_test2();
void remove_data_test3();
void remove_data_test4();

int main(void) {
    init_test1();
    add_data_test1();
    add_data_test2();
    find_data_test1();
    remove_data_test1();
    remove_data_test2();

    return 0;
}

void add_data_test1() {
    struct data datas[15];
    for (int i = 0; i < 15; i++) {
        datas[i].id = i;
        datas[i].status = i % 2;
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;

    struct node *current = root;
    for (int i = 0; i < 15; ++i) {
        current = add_data(current, &datas[i]);
    }

    printf("Add_node Test 1: Add Node After Root. It Should Become First. Test result: ");
    struct node *head = root->next;
    struct node *after_head = head->next;
    struct data new_data = {55, 55};
    struct node *new_node = add_data(root, &new_data);
    int checking_test1 = 1;
    if (!(root->next == new_node)) checking_test1 = 0;
    if (!(new_node->next == head)) checking_test1 = 0;
    if (!(new_node->data_data.id == 55)) checking_test1 = 0;
    if (!(new_node->data_data.status == 55)) checking_test1 = 0;
    if (!(after_head->data_data.id == 1)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");

    destroy(root);
    root = NULL;
}

void add_data_test2() {
    struct data datas[15];
    for (int i = 0; i < 15; i++) {
        datas[i].id = i;
        datas[i].status = i % 2;
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;

    struct node *current = root;
    for (int i = 0; i < 15; ++i) {
        current = add_data(current, &datas[i]);
    }

    printf("Add_node Test 2: Add Node After Last Element. It Should Become Last. Test result: ");
    struct node *tail = find_data(14, root);
    struct data new_data = {55, 55};
    struct node *new_node = add_data(tail, &new_data);
    int checking_test1 = 1;
    if (!(tail->next == new_node)) checking_test1 = 0;
    if (!(new_node->next == NULL)) checking_test1 = 0;
    if (!(new_node->data_data.id == 55)) checking_test1 = 0;
    if (!(new_node->data_data.status == 55)) checking_test1 = 0;
    if (!(tail->next->data_data.id == 55)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");

    /*

            public void AddToLast_Node_Should_Become_Tail()*/
    destroy(root);
    root = NULL;
}

void init_test1() {
    printf("Init_node Test 1: Init Node. Test result: ");
    struct data data1 = {21, 42};
    struct node *root = init(&data1);
    if (root->next->data_data.id == 21 && root->next->data_data.status == 42)
        printf("SUCCESS\n");
    else
        printf("FAIL\n");
    destroy(root);
    root = NULL;
}

void find_data_test1() {
    struct data datas[15];
    for (int i = 0; i < 15; i++) {
        datas[i].id = i;
        datas[i].status = i % 2;
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;

    struct node *current = root;
    for (int i = 0; i < 15; ++i) {
        current = add_data(current, &datas[i]);
    }
    printf("find_data() Test 1: Find Node. Test result: ");
    struct node *found = find_data(1, root);
    int checking_test1 = 1;
    if (!(found->data_data.id == 1)) checking_test1 = 0;
    if (!(found->data_data.status == 1)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");

    destroy(root);
    root = NULL;
}

void remove_data_test1() {
    struct data datas[15];
    for (int i = 0; i < 15; i++) {
        datas[i].id = i;
        datas[i].status = i % 2;
    }

    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;

    struct node *current = root;
    for (int i = 0; i < 15; ++i) {
        current = add_data(current, &datas[i]);
    }
    printf("remove_data() Test 1: Remove First Node. Test result: ");
    struct node *head = root->next;
    struct node *after_head = head->next;
    remove_data(head, root);

    int checking_test1 = 1;
    if (!(root->next == after_head)) checking_test1 = 0;
    if (!(after_head->data_data.id == 1)) checking_test1 = 0;
    if (!(after_head->data_data.status == 1)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    destroy(root);
    root = NULL;
}

void remove_data_test2() {
    printf("remove_data() Test 2: Remove Head Node. Test result: ");
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    head->data_data.id = 1;
    head->data_data.status = 1;
    root->next = head;
    struct node *ahead = (struct node *)malloc(sizeof(struct node));
    ahead->next = NULL;
    ahead->data_data.id = 21;
    ahead->data_data.status = 42;
    head->next = ahead;
    remove_data(head, root);
    int checking_test4 = 1;
    if (!(root->next == ahead)) checking_test4 = 0;
    if (!(ahead->next == NULL)) checking_test4 = 0;
    if (!(ahead->data_data.id == 21 && ahead->data_data.status == 42)) checking_test4 = 0;
    if (checking_test4)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    destroy(root);
    root = NULL;
}