#include <stdio.h>
#include <time.h>
#include "sort.h"

int main(int argc, char const *argv[])
{
  srandom(time(0));

  size_t len = 1001;
  int *arr = (int*)malloc(len*sizeof(int));
  
  //stores the length of the array
  arr[0]=len;

  //generate some random data for testing
  if (arr)
  {
    for (size_t i = 1; i < len; i++)
    {
      arr[i] = (rand() % (368 - 4 + 1)) + 4;
    }
  }
  else
  {
    printf("Failed to allocate memory!");
    return EXIT_FAILURE;
  }
 
  /* BUBBLE SORT */
  // bubble_sort(arr);

  /*SELECTION SORT*/
  selection_sort(arr);
  
  /*INSERTION SORT*/
  insertion_sort(arr);
  // recursive_insertion_sort(arr, (len - 2));

  for (size_t i = 1; i < len; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  //free the momory
  free(arr);

  return EXIT_SUCCESS;
}
