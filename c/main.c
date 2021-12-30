#include <stdio.h>
#include <time.h>
#include "sort.h"

int main(int argc, char const *argv[])
{
  srandom(time(0));

  list list;
  list.size = 5000000;
  list.items = (int*)malloc(list.size *sizeof(int));

  //generate some random data for testing
  if (list.items)
  {
    for (size_t i = 0; i < list.size; i++)
    {
      list.items[i] = (rand() % (978 - 5 + 1)) + 5;
    }
  }
  else
  {
    printf("Failed to allocate memory!");
    return EXIT_FAILURE;
  }
  for (size_t i = 0; i < list.size; i++)
  {
    printf("%d ", list.items[i]);
  }
  printf("\n\n");


  /* BUBBLE SORT */
  // bubblesort(list);

  /*SELECTION SORT*/
  // selectionsort(list);
  
  /*INSERTION SORT*/
  // insertionsort(list);
  // recursive_insertionsort(list, (list.size - 1));

  /*MERGE SORT*/
  // mergesort(list);
  // merge_sort(list);

  /*QUICKSORT*/
  quicksort(list);
  for (size_t i = 0; i < list.size; i++)
  {
    if (i%25==0 && i!=0)
    {
      printf("\n");
    }
    printf("%d\t", list.items[i]);   
  }
  printf("\n");
  
  //free the momory
  free(list.items);

  return EXIT_SUCCESS;
}
