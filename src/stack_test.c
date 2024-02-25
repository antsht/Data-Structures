#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push_test1();
void pop_test1();
void push_test2();
void push_null_test();
void pop_test1();
void pop_empty_test();
void pop_null_test();

int main(void) {
    push_test1();
    push_test2();
    push_null_test();
    pop_test1();

    pop_empty_test();
    pop_null_test();
    return 0;
}

void push_test1() {
    stack *s_root = init(666);
    push(21, s_root);

    printf("Test 1: Push 21 after init with 666 into stack. Test result: ");
    int checking_test1 = 1;
    if (!(s_root->next->value == 21)) checking_test1 = 0;
    if (!(s_root->next->next->value == 666)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    destroy(s_root);
    s_root = NULL;
}

void push_test2() {
    stack *s_root = init(0);
    push(0, s_root);

    printf("Test 2: Push 0 after init with 0 into stack. Test result: ");
    int checking_test1 = 1;
    if (!(s_root->next->value == 0)) checking_test1 = 0;
    if (!(s_root->next->next->value == 0)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    destroy(s_root);
    s_root = NULL;
}

void pop_test1() {
    stack *s_root = init(666);
    push(21, s_root);
    printf("Test 1: Pop element from stack. Test result: ");
    int checking_test1 = 1;
    if (!(pop(s_root) == 21)) checking_test1 = 0;
    if (!(pop(s_root) == 666)) checking_test1 = 0;
    if (checking_test1)
        printf("SUCCES\n");
    else
        printf("FAIL\n");
    destroy(s_root);
    s_root = NULL;
}
void push_null_test() {
    stack *s_root = NULL;

    push(10, s_root);

    if (s_root == NULL) {
        printf("Test 3: Push to null stack. Result: SUCCESS\n");
    } else {
        printf("Test 3: Push to null stack. Result: FAIL\n");
    }
}

void pop_empty_test() {
    stack *s_root = init(555);

    int val = pop(s_root);
    int val2 = pop(s_root);
    if (val2 == INT_MIN && val == 555 && s_root->next == NULL) {
        printf("Test 2: Pop from empty stack. Result: SUCCESS\n");
    } else {
        printf("Test 2: Pop from empty stack. Result: FAIL\n");
    }

    destroy(s_root);
}

void pop_null_test() {
    stack *s_root = NULL;

    int val = pop(s_root);

    if (val == INT_MIN && s_root == NULL) {
        printf("Test 3: Pop from null stack. Result: SUCCESS\n");
    } else {
        printf("Test 3: Pop from null stack. Result: FAIL\n");
    }
}
