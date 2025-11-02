#ifndef MAP_H
#define MAP_H

typedef int* Map;

Map map(unsigned long size);
Map map_add(Map map, int key, int val);
int map_get(Map map, int key);
int map_pop(Map map, int key);
void map_destroy(Map map);

#endif