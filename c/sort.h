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
  int size;
  int* items;
}list;

void swap(list, int, int);
void bubblesort(list list);
void selectionsort(list);
void insertionsort(list);
void recursive_insertionsort(list, int);
void mergesort(list);
void merge(list, list, list);
void merge_sort(list);
void mergesort_procedure(list, int, int);
void _merge_(list, int, int, int);
void quicksort(list);
void quicksort_procedure(list, int, int);
void countsort(list);
void radixsort(list);
void radix_countsort(list, int);
void buildmaxheap(list);
void heapsort(list);
void maxheapify(list, int, int);
int partition(list, int, int);
int median_of_three(list, int, int);
int getdigits(int);
int getmax(list);