
/*
Tests...

just need macro to print file and line on failure but no need to abort

main function

*/

#define HEADERS
#include "test_all.c"
#undef HEADERS

int main(void) {
  const char* test = "";

#define TESTS
#include "test_all.c"
#undef TESTS
  printf("\n");
}