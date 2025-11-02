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
  int index = _hash(key, (int)map.size);

  MapNode* node = map.backing_array[index];

  /*
  traverse to the end, if we find it, change the value, if we dont find it, then
   append to the end of the linked list
  */

  if (node == 0) {
    MapNode* new_node = malloc(sizeof(MapNode));
    new_node->key = key;
    new_node->val = val;
    new_node->next = 0;
    map.backing_array[index] = new_node;
    return map;
  }

  while (node != 0) {
    if (node->key == key) {
      node->val = val;
      return map;
    }

    if (node->next == 0) {
      break;
    }

    node = node->next;
  }

  MapNode* new_node = malloc(sizeof(MapNode));
  new_node->key = key;
  new_node->val = val;
  new_node->next = 0;
  node->next = new_node;
  return map;
}

ResultInt map_get(Map map, int key) {
  int index = _hash(key, (int)map.size);
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

ResultInt map_pop(Map map, int key) {
  int index = _hash(key, (int)map.size);
  ResultInt r;
  MapNode* node = map.backing_array[index];
  if (node == 0) {
    r.tag = ERR;
    r.err = "Not found";
    return r;
  }

  if (node->key == key) {
    map.backing_array[index] = node->next;
    r.tag = OK;
    r.ok = node->val;
    return r;
  }

  while (node->next != 0) {
    if (node->next->key == key) {
      r.tag = OK;
      r.ok = node->next->val;

      /* Remove this node from linked list before returning. */
      node->next = node->next->next;
      return r;
    }
    node = node->next;
  }

  r.tag = ERR;
  r.err = "Not found";
  return r;
}

void map_destroy(Map map);
