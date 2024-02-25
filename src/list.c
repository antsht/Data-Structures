#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node *init(struct data *data) {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data_data.id = 0;
    root->data_data.status = 0;

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    root->next = new_node;
    new_node->data_data.id = data->id;
    new_node->data_data.status = data->status;
    new_node->next = NULL;
    return root;
}

struct node *add_data(struct node *elem, struct data *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        ;
    } else {
        new_node->data_data.id = data->id;
        new_node->data_data.status = data->status;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node *find_data(int data_id, struct node *root) {
    struct node *curr = root;
    struct node *founded = (root->data_data.id == data_id) ? root : NULL;
    while (curr->next) {
        curr = curr->next;
        if (curr->data_data.id == data_id) {
            founded = curr;
            break;
        }
    }
    return founded;
}
struct node *remove_data(struct node *elem, struct node *root) {
    struct node *prev = root;
    if (elem == root) {
        ;
    } else {
        while (prev->next != elem && prev->next != NULL) {
            prev = prev->next;
        }
        if (prev->next == elem) {
            {
                if (elem->next)
                    prev->next = elem->next;
                else
                    prev->next = NULL;
                free(elem);
            }
        }
    }
    return prev;
}

void destroy(struct node *root) {
    while (root != NULL) {
        struct node *curr = root;
        root = root->next;
        free(curr);
    }
}