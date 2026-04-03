#include <stddef.h>
#include <stdio.h>

size_t str_len(char *str)
{
  char *stror;
  if (str == NULL) return 0;

  stror = str;

  while (*str) {
    ++str;
  }

  return (size_t)(str - stror);
}

char *rev_str(char *str)
{
  if (str == NULL) return NULL;

  char *left  = str;
  char *right = str + str_len(str) - 1;
  char tmp;

  while (left < right) {
    tmp = *right;
    *right = *left;
    *left = tmp;
    ++left;
    --right;
  }

  return str;
}

int main()
{
  char str[6] = "hello";

  rev_str(str);
  puts(str);

  return 0;
}
