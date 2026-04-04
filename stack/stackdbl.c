#include <stdio.h>
#include <malloc.h>

#define DEF_CAP 32
#define TRUE     1
#define FALSE    0

struct Stackdbl
{
  double   *dataptr;
  double   *headptr;
  unsigned  capacity;
};

unsigned stackdbl_len(struct Stackdbl *stack)
{
  return (unsigned) (stack->headptr - stack->dataptr);
}

void stackdbl_init(struct Stackdbl *stack)
{
  stack->dataptr  = (double *) malloc(DEF_CAP * sizeof(double));
  stack->headptr  = stack->dataptr;
  stack->capacity = DEF_CAP;
}

void stackdbl_destroy(struct Stackdbl *stack)
{
  free(stack->dataptr);
}

void stackdbl_push(struct Stackdbl *stack, double value)
{
  double *ndataptr;
  unsigned oldcap = stack->capacity;
  unsigned i;

  if (stackdbl_len(stack) == oldcap) {
    stack->capacity += DEF_CAP;
    ndataptr = (double *) malloc(stack->capacity * sizeof(double));
    for (i = 0; i < oldcap; ++i)
      ndataptr[i] = stack->dataptr[i];
    free(stack->dataptr);
    stack->dataptr = ndataptr;
    stack->headptr = stack->dataptr + i;
  }
  
  *(stack->headptr) = value;
  ++(stack->headptr);
}

int stackdbl_empty(struct Stackdbl *stack)
{
  return (stack->headptr == stack->dataptr) ? TRUE : FALSE;
}

double stackdbl_pop(struct Stackdbl *stack)
{
  if (stackdbl_empty(stack)) {
    fprintf(stderr, "Error: Can\'t pop from empty stack\n");
    return 0;
  }
  --(stack->headptr);
  double result = *(stack->headptr);
  return result;
}

int main()
{
  struct Stackdbl stack;
  unsigned i;
  double temp;

  stackdbl_init(&stack);

  for (i = 30; i < 70; ++i)  {
    stackdbl_push(&stack, (double)i);
    printf("pushed %.2f now %d capacity %d \n", (double)i, stackdbl_len(&stack), stack.capacity);
  }

  while ( !stackdbl_empty(&stack) ) {
    temp = stackdbl_pop(&stack);
    printf("pop %.2f now %d capacity %d \n", temp, stackdbl_len(&stack), stack.capacity);
  }

  stackdbl_push(&stack, 0.0f);
  printf("last %.2f \n", stackdbl_pop(&stack));

  stackdbl_pop(&stack);

  stackdbl_destroy(&stack);

  return 0;
}
