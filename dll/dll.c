#include "dll.h"
#include <malloc.h>
#include <stdlib.h>

DList *init_list(DList *list)
{
  if (list == NULL) return NULL;

  list->size = 0;
  list->head = NULL;
  list->tail = NULL;

  return list;
}

DNode *push_back(DList *list, int value)
{
  DNode *new_node;
  if (list == NULL) return NULL;

  new_node = malloc(sizeof(DNode));
  if (new_node == NULL) return NULL;

  if (list->tail) {
    new_node->prev = list->tail;
    new_node->next = NULL;
    new_node->value = value;
    list->tail->next = new_node;
  } else {
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = value;

    list->head = new_node;
  }

  list->tail = new_node;
  ++list->size;

  return new_node;
}

DNode *push_front(DList *list, int value)
{
  DNode *new_node;
  if (list == NULL) return NULL;

  new_node = malloc(sizeof(DNode));
  if (new_node == NULL) return NULL;

  if (list->head) {
    new_node->prev = NULL;
    new_node->next = list->head;
    new_node->value = value;
    list->head->prev = new_node;
  } else {
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->value = value;

    list->tail = new_node;
  }

  list->head = new_node;
  ++list->size;

  return new_node;
}

DNode *push_after(DList *list, DNode *after_node, int value)
{
  DNode *new_node;
  if (list == NULL || after_node == NULL) return NULL;

  new_node = malloc(sizeof(DList));
  new_node->value = value;

  ++list->size;

  if (list->tail == after_node) {
    after_node->next = new_node;
    new_node->prev = after_node;
    new_node->next = NULL;
    list->tail = new_node;
  } else {
    after_node->next->prev = new_node;
    new_node->next = after_node->next;
    new_node->prev = after_node;
    after_node->next = new_node;
  }

  return new_node;
}

DNode *push_before(DList *list, DNode *before_node, int value)
{
  DNode *new_node;

  if (list == NULL || before_node == NULL) return NULL;

  new_node = malloc(sizeof(DList));
  new_node->value = value;

  ++list->size;

  if (list->head == before_node) {
    new_node->prev = NULL;
    new_node->next = before_node;
    before_node->prev = new_node;
    list->head = new_node;
  } else {
    new_node->prev = before_node->prev;
    new_node->next = before_node;
    before_node->prev->next = new_node;
    before_node->prev = new_node;
  }

  return new_node;
}

DNode *pop_back(DList *list)
{
  DNode *popped;
  if (list == NULL || list->tail == NULL) return NULL;

  popped = list->tail;
  if (popped->next) {
    popped->next->prev = popped->prev;
  }
  if (popped->prev) {
    popped->prev->next = popped->next;
  } else {
    list->head = NULL;
  }
  list->tail = popped->prev;
  --list->size;

  return popped;
}

DNode *pop_front(DList *list)
{
  DNode *popped;
  if (list == NULL || list->head == NULL) return NULL;

  popped = list->head;
  if (popped->next) {
    popped->next->prev = popped->prev;
  } else {
    list->tail = NULL;
  }
  if (popped->prev) {
    popped->prev->next = popped->next;
  }
  list->head = popped->next;
  --list->size;

  return popped;
}

DNode *insert(DList *list, size_t index, int new_value)
{
  size_t half_size;
  DNode *node;
  DNode *new_node;

  if (list == NULL || index > list->size) return NULL;

  if (index == list->size) {
    /* insert to end */
    return push_back(list, new_value);
  }

  half_size = list->size / 2;

  if (index + 1 <= half_size) {
    /* start from head */
    node = list->head;
    while (index != 0) {
      node = node->next;
      --index;
    }
  } else {
    /* start from tail */
    node = list->tail;
    index = list->size - 1 - index;
    while (index != 0) {
      node = node->prev;
      --index;
    }
  }

  new_node = malloc(sizeof(DNode));
  new_node->value = new_value;

  if (node->prev == NULL) {
    list->head = new_node;
    node->prev = new_node;
    new_node->next = node;

    ++list->size;

    return new_node;
  }

  new_node->prev = node->prev;
  new_node->next = node;

  node->prev->next = new_node;
  node->prev = new_node;

  ++list->size;

  return new_node; 
}

DNode *remove_node(DList *list, size_t index) 
{
  size_t half_size;
  DNode *node;
  DNode *next_node;

  if (list == NULL || index >= list->size) return NULL;

  half_size = list->size / 2;

  if (index + 1 <= half_size) {
    /* start from head */
    node = list->head;
    while (index != 0) {
      node = node->next;
      --index;
    }
  } else {
    /* start from tail */
    node = list->tail;
    index = list->size - 1 - index;
    while (index != 0) {
      node = node->prev;
      --index;
    }
  }

  if (node->prev) {
    node->prev->next = node->next;
  } else {
    list->head = node->next;
  }

  if (node->next) {
    next_node = node->next;
    node->next->prev = node->prev;
  } else {
    list->tail = node->prev;
  }

  --list->size;
  free(node);

  return next_node;
}

DList *clear(DList *list)
{
  DNode *node;
  DNode *temp;
  if (list == NULL) return NULL;

  node = list->head;

  while (node) {
    temp = node;
    node = node->next;
    free(temp);
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}
