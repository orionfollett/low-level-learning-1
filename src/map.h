#ifndef MAP_H
#define MAP_H

// Map's contain linked lists
// So that I dont need to worry about resizing them.
typedef struct {
    unsigned long size;
    MapNode* backing_array;
} Map;

// TODO: swap this to take a tagged union to support multiple types?
// or make one that supports strings?
typedef struct {
    MapNode* next;
    int key;
    int val;
} MapNode;

Map map(unsigned long size);
Map map_add(Map map, int key, int val);
int map_get(Map map, int key);
int map_pop(Map map, int key);
void map_destroy(Map map);

#endif