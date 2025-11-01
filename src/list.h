#ifndef LIST_H
#define LIST_H


typedef int* List;

List list(unsigned long size);

void destroy_list(List list);

List list_append(List list, int val);

int list_get(List list, int index);

/*
insert, update, delete
sort
*/

#endif