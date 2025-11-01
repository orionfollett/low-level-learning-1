#include "list.h"
#include <stdlib.h>

List list(unsigned long size){
    return (List)malloc(((unsigned long) 2 + size) * sizeof(int));
}

void destroy_list(List list) {
    free(list);
}

List list_append(List list, int val);

int list_get(List list, int index);