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

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high]; 
  int i = (low - 1); 

  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;                   
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high); 
  }
}

int main()
{
  int count, size;

  printf("Enter number of elements\n");
  scanf("%d", &size);

  int *arr;

  arr = (int *)malloc(size * sizeof(int));

  printf("Enter %d integers in a disordered manner\n", size);

  for (count = 0; count < size; count++)
    scanf("%d", &arr[count]);

  printf("Before sorting: ");
  print_arr(arr, size);

  quicksort(arr, 0, size - 1);

  printf("After sorting:  ");
  print_arr(arr, size);

  free(arr);

  return 0;
}
