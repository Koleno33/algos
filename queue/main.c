#include <stdio.h>
#include "queue.h"

void show_queue(Queue *q) 
{
  Node *node = q->head;
  
  if (!q->size) {
    printf("empty queue\n");
    return;
  }

  while (node) {
    if (node->next) {
      printf("%d, ", node->value);
    } else {
      printf("%d", node->value);
      break;
    }
    node = node->next;
  }

  printf(" [%zu]\n", q->size);
}

int main()
{
  Queue q;
  Node *node;
  init_queue(&q);

  push_back(&q, 5);
  push_back(&q, 4);
  push_back(&q, 3);
  push_back(&q, 2);
  push_back(&q, 1);

  show_queue(&q);

  while (q.size) {
    printf("pop from queue\n");
    node = pop_front(&q);
    printf("%d\n", node->value);
    free(node);
  }

  show_queue(&q);

  return 0;
}
