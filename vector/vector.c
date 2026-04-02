#include <stdio.h>
#include <stddef.h>
#include <malloc.h>

#define CAPACITY_MUL 2

typedef struct 
{
  int    *data;
  size_t  size;
  size_t  capacity;
} Vector;

void vector_init(Vector *vec, size_t init_cap)
{
  vec->capacity = init_cap;
  vec->data     = malloc(init_cap * sizeof(int));
  vec->size     = 0;
}

void vector_push(Vector *vec, int value)
{
  size_t old_cap = vec->capacity;

  if (vec->size == old_cap) {
    vec->capacity = old_cap * CAPACITY_MUL;
    vec->data = realloc(vec->data, vec->capacity * sizeof(int));
  }
  
  vec->data[(vec->size)++] = value;
}

int *vector_insert(Vector *vec, size_t pos, int value)
{
  size_t old_cap = vec->capacity;
  size_t index;

  if (pos >= vec->size) {
    return NULL;
  }

  if (vec->size == old_cap) {
    vec->capacity = old_cap * CAPACITY_MUL;
    vec->data = realloc(vec->data, vec->capacity * sizeof(int));
  }

  for (index = vec->size; index > 0; --index) {
    vec->data[index] = vec->data[index - 1];
  }

  ++vec->size;
  vec->data[pos] = value;

  return vec->data + pos;
}

int *vector_get(Vector *vec, size_t index)
{
  if (index < vec->size) {
    return vec->data + index;
  }

  return NULL;
}

void vector_free(Vector *vec)
{
  free(vec->data);
  vec->data = NULL;
  vec->size = 0;
  vec->capacity = 0;
}

int main(void)
{
  size_t vec_i;
  int *vec_el;

  Vector vec1;
  vector_init(&vec1, 16);

  vector_push(&vec1, 1);
  vector_push(&vec1, 2);
  vector_push(&vec1, 3);
  vector_push(&vec1, 4);
  printf("Pushed 4 elements: %zu/%zu\n", vec1.size, vec1.capacity);
  vector_push(&vec1, 1);
  vector_push(&vec1, 2);
  vector_push(&vec1, 3);
  vector_push(&vec1, 4);
  printf("Pushed 4 elements: %zu/%zu\n", vec1.size, vec1.capacity);
  vector_push(&vec1, 1);
  vector_push(&vec1, 2);
  vector_push(&vec1, 3);
  vector_push(&vec1, 4);
  printf("Pushed 4 elements: %zu/%zu\n", vec1.size, vec1.capacity);
  vector_push(&vec1, 1);
  vector_push(&vec1, 2);
  vector_push(&vec1, 3);
  vector_push(&vec1, 4);
  printf("Pushed 4 elements: %zu/%zu\n", vec1.size, vec1.capacity);
  vector_push(&vec1, 1);
  vector_push(&vec1, 2);
  vector_push(&vec1, 3);
  vector_push(&vec1, 4);
  printf("Pushed 4 elements: %zu/%zu\n", vec1.size, vec1.capacity);

  vector_insert(&vec1, 0, 33);
  printf("Inserted 1 element 33 at pos 0: %zu/%zu\n", vec1.size, vec1.capacity);

  vector_insert(&vec1, 0, 33);
  printf("Inserted 1 element 33 at pos 5: %zu/%zu\n", vec1.size, vec1.capacity);

  vector_insert(&vec1, 0, 33);
  printf("Inserted 1 element 33 at pos 5: %zu/%zu\n", vec1.size, vec1.capacity);

  vector_insert(&vec1, 3, 33);
  printf("Inserted 1 element 33 at pos 5: %zu/%zu\n", vec1.size, vec1.capacity);

  for (vec_i = 0; vec_i < vec1.size; ++vec_i) {
    vec_el = vector_get(&vec1, vec_i);
    printf("%d\n", *vec_el);
  }

  vector_free(&vec1);
  return 0;
}
