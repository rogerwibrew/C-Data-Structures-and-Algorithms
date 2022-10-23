#include "list.h"
#include <stdlib.h>

#include <stdio.h>

int main(int argc, char *argv[]) {

  int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  List *myList = (List *)malloc(sizeof(List));

  list_init(myList, NULL);

  int i = 0;
  int array_length = 10;

  for (i = 0; i < array_length; i++) {
    list_ins_next(myList, NULL, values);
  }

  printf("This appears to work\n");

  free(myList);

  return 0;
}
