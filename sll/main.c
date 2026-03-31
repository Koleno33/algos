#include <stdio.h>
#include "sll.h"

void print_l(const List *list)
{
  Node *node = list->head;
  printf("[");
  while (node != NULL) {
    printf("%d", node->value);
    if (node->next != NULL) {
      printf(", ");
    } else {
      break;
    }
    node = node->next;
  }
  printf("](%zu)\n", list->size);
}

int main(void)
{
  List list;
  Node *temp;
  init_list(&list);

  print_l(&list);

  insert(&list, 1, -2);
  insert(&list, 0, -2);
  push_front(&list, 33);
  push_front(&list, 3);
  push_front(&list, 5);
  insert_after(&list, list.head, 0);
  insert(&list, 1, -1);
  print_l(&list);

  insert(&list, 2, -9);
  push_back(&list, 100);
  print_l(&list);

  for (int i = 0; i < 5; ++i) {
    temp = pop_tail(&list);
    if (temp != NULL) {
      printf("pop from T: %d\n", temp->value);
      free(temp);
    }
  }
  temp = NULL;
  print_l(&list);

  for (int i = 0; i < 4; ++i) {
    temp = pop_head(&list);
    if (temp != NULL) {
      printf("pop from H: %d\n", temp->value);
      free(temp);
    }
  }
  temp = NULL;
  print_l(&list);

  push_front(&list, 5);
  push_front(&list, 4);
  print_l(&list);

  rem_head(&list);
  print_l(&list);
  rem_head(&list);
  print_l(&list);
  rem_head(&list);
  print_l(&list);

  push_front(&list, 8);
  push_front(&list, 7);
  print_l(&list);

  rem_tail(&list);
  print_l(&list);
  rem_tail(&list);
  print_l(&list);
  rem_tail(&list);
  print_l(&list);

  for (int i = 0; i < 10; ++i) {
    temp = push_front(&list, i);
    if (temp != NULL) {
      printf("pushed to H: %d\n", temp->value);
    }
  }
  temp = NULL;
  print_l(&list);

  temp = get(&list, 0);
  printf("got by index %d: %d\n", 0, temp->value);

  temp = find(&list, -1);
  if (temp == NULL) {
    puts("can not find -1 val");
  } else {
    printf("got by value %d: %d\n", -1, temp->value);
  }

  temp = NULL;

  clear(&list);
  printf("list cleared\n");

  print_l(&list);

  return 0;
}
