#include <stdlib.h>
#include <string.h>

#include "dlist.h"

void dlist_init(DList *list, void (*destroy)(void *data)) {
  list->size = 0;
  list->destroy = destroy;
  list->head = NULL;
  list->tail = NULL;

  return;
}

void dlist_destroy(DList *list) {
  void *data;

  while (dlist_size(list) > 0) {
    if (dlist_remove(list, dlist_tail(list), (void **)&data) == 0 &&
        list->destroy != NULL) {
      list->destroy(data);
    }
  }

  memset(list, 0, sizeof(DList));

  return;
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data) {

  DListElmt *new_element;

  // Do not allow a NULL element unless teh list is empty

  if (element == NULL && dlist_size(list) != 0)
    return -1;

  // Allocate storage for the elment.

  if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
    return -1;

  // Insert the new element into the list

  new_element->data = (void *)data;

  if (dlist_size(list) == 0) {

    // Handle the insertion wen the list is empty.

    list->head = new_element;
    list->head->prev = NULL;
    list->head->next = NULL;
    list->tail = new_element;
  } else {
    // Handle insertion wen the list is not empty

    new_element->next = element->next;
    new_element->prev = element;

    if (element->next == NULL)
      list->tail = new_element;
    else
      element->next->prev = new_element;

    element->next = new_element;
  }

  // Adjust the size of the lsit to account for the inserted element.

  list->size++;
  return 0;
}
