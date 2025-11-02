#ifndef MAP_H
#define MAP_H

/* TODO: swap this to take a tagged union to support multiple types? */
/* or make one that supports strings? */
typedef struct MapNode {
  int key;
  int val;
  struct MapNode* next;
} MapNode;

/* Map's contain linked lists */
/* So that I dont need to worry about resizing them. */
typedef struct Map {
  unsigned long size;
  MapNode** backing_array;
} Map;

typedef enum { OK, ERR } ResultTag;

typedef struct ResultInt {
  ResultTag tag;
  union {
    int ok;
    const char* err;
  };
} ResultInt;

Map map(unsigned long size);
Map map_set(Map map, int key, int val);
ResultInt map_get(Map map, int key);
ResultInt map_pop(Map map, int key);
void map_destroy(Map map);

#endif