#include "map.h"
#include <stdlib.h>

static int _hash(int val, int max) {
  return val % max;
}

Map map(unsigned long size) {
  Map m;
  m.backing_array = (MapNode**)calloc(size, sizeof(MapNode*));
  m.size = size;
  return m;
}

Map map_set(Map map, int key, int val) {
  int index = _hash(key, map.size);

  MapNode* node = map.backing_array[index];

  //

  return map;
}

ResultInt map_get(Map map, int key) {
  int index = _hash(key, map.size);
  ResultInt r;
  MapNode* node = map.backing_array[index];
  while (node != 0) {
    if (node->key == key) {
      r.tag = OK;
      r.ok = node->val;
      return r;
    }
    node = node->next;
  }
  r.tag = ERR;
  r.err = "Not found";
  return r;
}

ResultInt map_pop(Map map, int key);

void map_destroy(Map map);
