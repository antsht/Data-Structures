#ifndef LIST_H
#define LIST_H

struct data {
    int id;
    int status;
};

struct node {
    struct data data_data;
    struct node *next;
};

struct node *init(struct data *data);
struct node *add_data(struct node *elem, struct data *data);
struct node *find_data(int data_id, struct node *root);
struct node *remove_data(struct node *elem, struct node *root);
void destroy(struct node *root);

#endif
