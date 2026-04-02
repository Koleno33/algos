#ifndef SLL_H
#define SLL_H

#include <stddef.h>
#include <malloc.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

typedef struct
{
  size_t size;
  Node *head;
} List;

List *init_list(List *l);
List *clear_list(List *l);
Node *create_node(int data);
Node *push_front(List *l, Node *element);
Node *push_back(List *l, Node *element);
Node *insert(List *l, Node *after_element, Node *element);
Node *find(List *l, int f_data);
Node *remove_head(List *l);
Node *remove_after(List *l, Node *after_node);
Node *remove_tail(List *l);

#endif
