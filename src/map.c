#include "map.h"
#include <stdlib.h>

static int _hash(int val, int max){
    return val % max;
}

Map map(unsigned long size) {
    Map m;
    m.backing_array = (MapNode*) malloc(size * sizeof(MapNode));
    m.size = size;
    return m;
}

Map map_add(Map map, int key, int val) {
        
}

int map_get(Map map, int key);
int map_pop(Map map, int key);
void map_destroy(Map map);
