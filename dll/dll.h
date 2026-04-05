#ifndef DLL_H
#define DLL_H

#include <stddef.h>

typedef struct dnode
{
  int value;
  dnode *next;
  dnode *prev;
} DNode;

typedef struct 
{
  size_t size;
  DNode *head;
  DNode *tail;
} DList;

DList *init_list(DList *list);

DNode *push_back(DList *list, int value);
DNode *push_front(DList *list, int value);

DNode *push_after(DList *list, DNode *after_node, int value);
DNode *push_before(DList *list, DNode *before_node, int value);

DNode *pop_back(DList *list);
DNode *pop_front(DList *list);

DNode *insert(DList *list, size_t index, int new_value);

DNode *remove(DList *list, size_t index);

#endif
