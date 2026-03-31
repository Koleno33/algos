#ifndef SLL_H
#define SLL_H

#include <stddef.h>
#include <malloc.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct
{
  size_t size;
  Node *head;
} List;

List *init_list(List *list);

Node *push_front(List *list, int new_value);
Node *push_back(List *list, int new_value);
Node *insert_after(List *list, Node *node, int new_value);
Node *insert(List *list, size_t index, int new_value);

Node *rem_head(List *list);
Node *rem_tail(List *list);
Node *rem_after(List *list, Node *node);

Node *pop_head(List *list);
Node *pop_tail(List *list);

Node *get(List *list, size_t index);
Node *find(List *list, int value);

List *clear(List *list);

#endif
