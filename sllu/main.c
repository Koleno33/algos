#include <stdio.h>
#include "sll.h"

void print_list(List *l)
{
  Node *next_node = l->head;

  puts("--- LIST START ---");
  while (next_node != NULL) {
    printf("%d\n", next_node->data);
    next_node = next_node->next;
  }
  puts("*** LIST END ***");
}

int main()
{
  List l;
  Node *next_node;
  init_list(&l);

  next_node = create_node(33);
  push_front(&l, next_node);

  print_list(&l);
  clear_list(&l);
  print_list(&l);

  next_node = create_node(45);
  push_back(&l, next_node);
  Node *prev_node = next_node;
  next_node = create_node(-13);
  push_front(&l, next_node);
  next_node = create_node(-12);
  push_front(&l, next_node);
  next_node = create_node(0);
  insert(&l, prev_node, next_node);
  print_list(&l);
  next_node = remove_tail(&l);
  free(next_node);
  next_node = remove_tail(&l);
  free(next_node);
  next_node = remove_tail(&l);
  free(next_node);
  next_node = remove_tail(&l);
  free(next_node);
  next_node = remove_head(&l);
  free(next_node);
  print_list(&l);
  clear_list(&l);
  print_list(&l);

  return 0;
}
