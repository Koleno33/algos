#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

typedef struct queue
{
  Node   *head;
  Node   *tail;
  size_t  size;
} Queue;

Queue *init_queue(Queue *q);
Node  *push_back(Queue *q, int value);
Node  *pop_front(Queue *q);

#endif
