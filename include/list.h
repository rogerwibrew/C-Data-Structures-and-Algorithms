#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

// define a structure for linked lists elements.

typedef struct ListElemnt_ {

  void *data;
  struct ListElemnt_ *next;
} ListElemnt;

// Define a strucutre for linked lists

typedef struct List_ {
  int size;

  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  ListElemnt *head;
  ListElemnt *tail;
} List;

// Public Interface

void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
int list_ins_next(List *list, ListElemnt *element, const void *data);
int list_rem_next(List *list, ListElemnt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element)->next == NUL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
