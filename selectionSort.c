#include <stdio.h>
#include <stdlib.h>

void print_arr(int *array, int size)
{
  putchar('[');
  while (size--)
  {
    printf("%d", *array++);
    if (size)
      putchar(',');
  }
  printf("]\n");
}

int *find_min(int *array, int size)
{
  int *min = array;

  while(size--)
  {
    if (*array < *min)
      min = array;
    array++;
  }
  
  return (min);
}

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

void selection_sort(int *array, int size)
{
  int *min;

  while (--size)
  {
    min = find_min(array + 1, size);

    if (*array > *min)
      swap(array, min);

    array++;
  }
}

int main()
{
  int count, size;

  printf("Enter number of elements\n");
  scanf("%d", &size);

  int *array;

  array = (int *)malloc(size * sizeof(int));

  printf("Enter %d integers in a disordered manner\n", size);

  for (count = 0; count < size; count++)
    scanf("%d", &array[count]);

  printf("Before sorting: ");
  print_arr(array, size);

  selection_sort(array, size);

  printf("After sorting:  ");
  print_arr(array, size);

  free(array);

  return 0;
}