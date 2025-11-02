#include "list.h"
#include <stdlib.h>

const int LEN_INDEX = 0;
const int SIZE_INDEX = 1;

List list(unsigned long size) {
  List list = (List)malloc(((unsigned long)2 + size) * sizeof(int));
  list[LEN_INDEX] = 0;
  list[SIZE_INDEX] = (int)size;
  return list;
}

void destroy_list(List list) {
  free(list);
}

List list_append(List list, int val) {
  int len = list[LEN_INDEX];
  int size = list[SIZE_INDEX];

  if (size <= len) {
    int new_size = (1 + size) * 2;
    list[SIZE_INDEX] = new_size;
    list = realloc(list, (unsigned long)(2 + new_size) * sizeof(int));
  }

  list[len + 2] = val;
  list[LEN_INDEX] = len + 1;
  return list;
}

int list_get(List list, int index) {
  return list[index + 2];
}

int list_len(List list) {
  return list[LEN_INDEX];
}

List list_insert(List list, int index, int val) {
  /*
  resize if len = size
  loop through the list, and shift all the values up one
  */
  int len = list[LEN_INDEX];
  int size = list[SIZE_INDEX];
  if (len >= size) {
    unsigned long new_size = (unsigned long)(size + 1) * 2;
    list = realloc(list, new_size * sizeof(int));
    list[SIZE_INDEX] = (int)new_size;
  }
  list[LEN_INDEX] = len + 1;

  len = len + 2;
  index = index + 2;
  int i = index;
  for (; i < len + 1; i++) {
    int temp = list[i];
    list[i] = val;
    val = temp;
  }
  return list;
}

void list_update(List list, int index, int val) {
  index = index + 2;
  list[index] = val;
}

int list_delete(List list, int index);

int find(List list, int val);
