#include "sll.h"
#include <stdio.h>

List *init_list(List *list)
{
  if (list == NULL) return NULL;

  list->size = 0;
  list->head = NULL;

  return list;
}

Node *push_front(List *list, int new_value)
{
  Node *new_node;
  if (list == NULL) return NULL;

  new_node = malloc(sizeof(Node));
  if (new_node == NULL) return NULL;

  new_node->value = new_value;
  new_node->next = list->head;

  list->head = new_node;

  ++list->size;

  return new_node;
}

Node *push_back(List *list, int new_value)
{
  Node *new_node;
  Node *tail;
  if (list == NULL) return NULL;

  new_node = malloc(sizeof(Node));
  if (new_node == NULL) return NULL;

  new_node->value = new_value;
  new_node->next = NULL;

  tail = list->head;
  if (tail == NULL) {
    list->head = new_node;
    ++list->size;
    return new_node;
  }

  while (tail->next != NULL) {
    tail = tail->next;
  }

  tail->next = new_node;
  ++list->size;

  return new_node;
}

Node *insert_after(List *list, Node *node, int new_value)
{
  Node *new_node;
  if (list == NULL || node == NULL) return NULL;

  new_node = malloc(sizeof(Node));
  if (new_node == NULL) return NULL;

  new_node->value = new_value;
  new_node->next = node->next;

  node->next = new_node;

  ++list->size;

  return new_node;
}

Node *insert(List *list, size_t index, int new_value)
{
  Node *node;
  Node *new_node;
  if (list == NULL) return NULL;

  if (index == 0) {
    new_node = malloc(sizeof(Node));
    if (new_node == NULL) return NULL;
    new_node->value = new_value;
    new_node->next = list->head;
    list->head = new_node;
    ++list->size;
    return new_node;
  }

  node = list->head;

  if (node == NULL) return NULL;

  while(index != 1) {
    if (node == NULL) {
      return NULL;
    }
    node = node->next;
    --index;
  }

  new_node = malloc(sizeof(Node));
  if (new_node == NULL) return NULL;

  new_node->value = new_value;
  new_node->next = node->next;

  node->next = new_node;

  ++list->size;

  return new_node;
}

Node *rem_head(List *list)
{
  Node *new_head;
  if (list == NULL || list->head == NULL) return NULL;

  new_head = list->head->next;

  free(list->head);
  list->head = new_head;

  --list->size;

  return new_head;
}

Node *rem_tail(List *list)
{
  Node *tail;
  Node *prev_tail;
  if (list == NULL) return NULL;

  prev_tail = list->head;
  if (prev_tail == NULL) return NULL;

  tail = prev_tail->next;

  if (tail == NULL) {
    list->head = NULL;
    --list->size;
    free(prev_tail);
    return NULL;
  }

  while(tail->next != NULL) {
    prev_tail = tail;
    tail = tail->next;
  }

  prev_tail->next = NULL;
  --list->size;

  free(tail);
  return prev_tail;
}

Node *rem_after(List *list, Node *node)
{
  Node *next;
  Node *new_next;
  if (list == NULL || node == NULL || node->next == NULL) return NULL;

  next = node->next;
  new_next = next->next;

  free(next);
  node->next = new_next;

  --list->size;

  return node;
}

Node *pop_head(List *list)
{
  Node *old_head;
  if (list == NULL || list->head == NULL) return NULL;

  old_head = list->head;

  list->head = old_head->next;

  --list->size;
  old_head->next = NULL;

  return old_head;
}

Node *pop_tail(List *list)
{
  Node *tail;
  Node *prev_tail;
  if (list == NULL) return NULL;

  prev_tail = list->head;
  if (prev_tail == NULL) return NULL;

  tail = prev_tail->next;

  if (tail == NULL) {
    list->head = NULL;
    --list->size;
    return prev_tail;
  }

  while(tail->next != NULL) {
    prev_tail = tail;
    tail = tail->next;
  }

  prev_tail->next = NULL;
  --list->size;

  return tail;
}

Node *get(List *list, size_t index)
{
  Node *node;
  if (list == NULL) return NULL;

  node = list->head;

  while(index != 0) {
    if (node == NULL) {
      return NULL;
    }
    node = node->next;
    --index;
  }

  return node;
}

Node *find(List *list, int value)
{
  Node *node;
  if (list == NULL) return NULL;

  node = list->head;

  while(node != NULL) {
    if (node->value == value) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

List *clear(List *list)
{
  Node *node;
  Node *temp;
  if (list == NULL) return NULL;

  node = list->head;

  while (node) {
    temp = node;
    node = node->next;
    free(temp);
  }

  list->head = NULL;
  list->size = 0;

  return list;
}

