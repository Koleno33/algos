#include "sll.h"
#include <stdlib.h>

List *init_list(List *l)
{
  l->size = 0;
  l->head = NULL;
  return l;
}

List *clear_list(List *l)
{
  Node *next_node = l->head;
  Node *temp_node = l->head;

  while (next_node != NULL) {
    next_node = next_node->next;
    free(temp_node);
    temp_node = next_node;
  }

  l->head = NULL;
  l->size = 0;
  return l;
}

Node *create_node(int data)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

Node *push_front(List *l, Node *element)
{
  if (l == NULL) return NULL;

  element->next = l->head;
  l->head = element;
  ++l->size;

  return element;
}

Node *push_back(List *l, Node *element)
{
  Node *last;
  if (l == NULL) return NULL;

  last = l->head;
  if (last == NULL) {
    push_front(l, element);
    return element;
  }

  while (last->next != NULL) {
    last = last->next;
  }

  last->next = element;
  element->next = NULL;
  ++l->size;

  return element;
}

Node *insert(List *l, Node *after_element, Node *element) 
{
  if (l == NULL || after_element == NULL || element == NULL) return NULL;

  element->next = after_element->next;
  after_element->next = element;
  ++l->size;

  return element;
}

Node *find(List *l, int f_data)
{
  Node *node;
  if (l == NULL || l->head == NULL) return NULL;

  node = l->head;

  while (node->data != f_data) {
    if (node->next == NULL) return NULL;
    node = node->next;
  }

  return node;
}

Node *remove_head(List *l) 
{
  Node *next;
  Node *original;
  if (l == NULL) return NULL;

  original = l->head; 
  if (original == NULL) return NULL;

  next = l->head->next;
  l->head = next;
  --l->size;

  return original;
}

Node *remove_after(List *l, Node *after_node)
{
  Node *removed;
  if (after_node == NULL || l == NULL) return NULL;

  removed = after_node->next;
  if (removed == NULL) return NULL;
  after_node->next = removed->next;

  return removed;
}

Node *remove_tail(List *l)
{
  Node *prev;
  Node *last;
  if (l == NULL || l->head == NULL) return NULL;

  prev = l->head;
  last = prev->next;

  if (last == NULL) {
    prev->next = NULL;
    return last;
  }

  while (last->next != NULL) {
    prev = last;
    last = last->next;
  }

  prev->next = NULL;
  --l->size;

  return last;
}
