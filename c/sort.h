#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief represents the list structure for the data to be sorted
 * 
 */
typedef struct
{
  size_t size;
  int* items;
}list;

void swap(list, size_t, size_t);
void bubblesort(list list);
void selectionsort(list);
void insertionsort(list);
void recursive_insertionsort(list, int);
void mergesort(list);
void merge(list, list, list);
void merge_sort(list);
void mergesort_procedure(list, size_t, size_t);
void _merge_(list, size_t, size_t, size_t);
void quicksort(list);
void quicksort_procedure(list, size_t, size_t);
int partition(list, size_t, size_t);
int median_of_three(list, size_t, size_t);
void countsort(list);
void radixsort(list);
void radix_countsort(list, int);
int getdigits(int);
int getmax(list);