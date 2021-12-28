#include <stdlib.h>

/**
 * @brief represents the list structure for the data to be sorted
 * 
 */
typedef struct
{
  size_t size;
  int* items;
}list;

void bubblesort(list list);
void selectionsort(list);
void insertionsort(list);
void recursive_insertionsort(list, int);
void mergesort(list);
void merge(list, list, list);