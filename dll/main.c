#include <stdio.h>
#include <malloc.h>
#include "dll.h"

void print_l(const DList *list)
{
  DNode *node = list->head;
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
  DList list;
  DNode *temp;

  init_list(&list);
  printf("list initialized\n");
  print_l(&list);

  push_front(&list, 0);
  printf("push front 0\n");
  print_l(&list);

  push_back(&list, 22);
  printf("push back 22\n");
  print_l(&list);

  push_back(&list, 33);
  printf("push back 33\n");
  print_l(&list);

  push_back(&list, -5);
  printf("push back -5\n");
  print_l(&list);

  insert(&list, 0, 9);
  printf("insert by index 0 value 9\n");
  print_l(&list);

  insert(&list, list.size, 15);
  printf("insert by index end value 15\n");
  print_l(&list);

  insert(&list, 3, -99);
  printf("insert by index 3 value -99\n");
  print_l(&list);

  remove_node(&list, 1);
  printf("remove by index 1\n");
  print_l(&list);

  remove_node(&list, 2);
  printf("remove by index 2\n");
  print_l(&list);

  remove_node(&list, 1);
  printf("remove by index 1\n");
  print_l(&list);

  remove_node(&list, 0);
  printf("remove by index 0\n");
  print_l(&list);

  temp = pop_front(&list);
  printf("pop from front with val %d\n", temp->value);
  print_l(&list);
  free(temp);

  temp = pop_back(&list);
  printf("pop from back with val %d\n", temp->value);
  print_l(&list);
  free(temp);

  temp = pop_front(&list);
  printf("pop from front with val %d\n", temp->value);
  print_l(&list);
  free(temp);

  push_back(&list, 1);
  printf("push back 1\n");
  print_l(&list);

  push_back(&list, 2);
  printf("push back 2\n");
  print_l(&list);

  push_before(&list, list.head, 3);
  printf("push 3 before head\n");
  print_l(&list);

  temp = push_after(&list, list.tail, 6);
  printf("push 6 after tail\n");
  print_l(&list);

  push_back(&list, -33);
  printf("push back -33\n");
  print_l(&list);

  push_before(&list, temp, 99);
  printf("push 99 before 6\n");
  print_l(&list);

  temp = push_after(&list, temp, 33);
  printf("push 33 after 6\n");
  print_l(&list);

  temp = NULL;

  clear(&list);
  printf("list cleared\n");
  print_l(&list);

  return 0;
}
