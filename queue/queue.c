#include "queue.h"
#include <malloc.h>

Queue *init_queue(Queue *q)
{
  if (q == NULL) return NULL;
  q->head = NULL;
  q->tail = NULL;
  q->size = 0;
  return q;
}

Node *push_back(Queue *q, int value)
{
  Node *new_node;
  if (q == NULL) return NULL;

  new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;

  if (q->head == NULL) {
    q->head = new_node;
  }

  if (q->tail) {
    q->tail->next = new_node;
  }

  q->tail = new_node;

  ++q->size;

  return new_node;
}

Node *pop_front(Queue *q)
{
  Node *node;
  if (q == NULL || q->head == NULL) return NULL;

  node = q->head;
  q->head = q->head->next;
  --q->size;

  return node;
}

