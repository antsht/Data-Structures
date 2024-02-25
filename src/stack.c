#include "stack.h"

#include <stdlib.h>

stack *init(int value) {
    stack *s_root = (stack *)malloc(sizeof(stack));
    s_root->next = NULL;
    s_root->value = INT_MIN;
    stack *s_head = (stack *)malloc(sizeof(stack));
    s_head->value = value;
    s_head->next = NULL;
    s_root->next = s_head;
    return s_root;
}

void push(int value, stack *s_root) {
    if (s_root == NULL) return;
    stack *s_node = (stack *)malloc(sizeof(stack));
    s_node->next = s_root->next;
    s_node->value = value;
    s_root->next = s_node;
}

int pop(stack *s_root) {
    int value = INT_MIN;
    if (s_root && s_root->next != NULL) {
        stack *s_node = s_root->next;
        value = s_node->value;
        s_root->next = s_node->next;
        free(s_node);
    }
    return value;
}

void destroy(stack *root) {
    stack *curr = root;
    stack *next;

    while (curr != NULL && curr->next) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(curr);
    curr = NULL;
    next = NULL;
}