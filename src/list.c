#include "list.h"
#include <stdlib.h>

const int LEN_INDEX = 0;
const int SIZE_INDEX = 1;

List list(unsigned long size){
    List list = (List)malloc(((unsigned long) 2 + size) * sizeof(int));
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
    
    
    if(size <= len){
        int new_size = size * 2;
        list[SIZE_INDEX] = new_size;
        list = realloc(list, ((unsigned long) 2 + new_size) * sizeof(int));
    }

    list[len + 2] = val;
    return list;
}

int list_get(List list, int index) {
    return list[index + 2];
}