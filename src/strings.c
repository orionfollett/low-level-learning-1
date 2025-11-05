#include "strings.h"
#include <stdlib.h>
#include <string.h>

s8 str(const char* s) {
  /*Make a s8 from a null terminated c string.*/
  s8 str;
  unsigned long len = 0;
  char c = s[len];
  while (c != 0) {
    len++;
    c = s[len];
  }

  char* copy = malloc(len * sizeof(char));
  memcpy(copy, s, len);
  str.len = len;
  str.str = copy;
  return str;
}

int s8cmp(s8 s1, s8 s2) {
  if (s1.len != s2.len) {
    return 0;
  }
  int i = 0;
  for (; (unsigned long)i < s1.len; i++) {
    if (s1.str[i] != s2.str[i]) {
      return 0;
    }
  }
  return 1;
}
