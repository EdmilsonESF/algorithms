#include <stdio.h>

void binary_search(int search, int *array, int array_length)
{
  int first = 0;
  int last = array_length - 1;

  while (first <= last)
  {
    int middle = (first + last) / 2;
    int guess = array[middle];

    if (guess == search)
    {
      printf("%d found at location %d.\n", search, middle);
      break;
    }
    else if (guess > search)
      last = middle - 1;
    else
      first = middle + 1;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", search);
}

int main()
{
  int count, array_length, search;

  printf("Enter number of elements\n");
  scanf("%d", &array_length);

  int array[array_length];

  printf("Enter %d integers\n", array_length);

  for (count = 0; count < array_length; count++)
    scanf("%d", &array[count]);

  printf("Enter value to find\n");
  scanf("%d", &search);

  binary_search(search, array, array_length);

  return 0;
}