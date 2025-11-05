#ifndef STRINGS_H
#define STRINGS_H

typedef struct s8 {
  char* str;
  unsigned long len;
} s8;

s8 str(const char* s);
int s8cmp(s8 s1, s8 s2);

#endif