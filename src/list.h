#ifndef LIST_H
#define LIST_H

typedef int* List;

List list(unsigned long size);

void destroy_list(List list);

List list_append(List list, int val);

int list_get(List list, int index);

int list_len(List list);

List list_insert(List list, int index, int val);

List list_update(List list, int index, int val);

List list_delete(List list, int index);

int list_find(List list, int val);

#endif