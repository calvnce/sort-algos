#include "sort.h"
#include <stdio.h>

/**
 * @brief performs bubble sort on the provided array or values. 
 * The default sorting mode is ascending.
 * Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements 
 * and then swapping their positions if they exist in the wrong order. 
 * 
 * @param lst 
 */
void bubblesort(list lst)
{ 
  for (size_t i = 0; i < lst.size; i++)
  {
    int swapped = 0;
    for (size_t j = 0; j < lst.size - i - 1; j++)
    {
      if (lst.items[j] > lst.items[j + 1])
      {
        int temp = lst.items[j];
        lst.items[j] = lst.items[j + 1];
        lst.items[j+1] = temp;
        
        swapped = 1;
      }
    }
    //After an iteration, if there is no swapping, the value of swapped will be false:=0. 
    //This means elements are already sorted and there is no need to perform further iterations.
    //This will reduce the execution time and helps to optimize the bubble sort.
    if (swapped == 0)
    {
      break;
    }
  }
}

/**
 * @brief - performs selection sort on the provided array or values. 
 * The default sorting mode is ascending
 * The algorithm divides the input list into two parts: 
 *  - a sorted sublist of items which is built up from left to right at the front (left) of the list and 
 *  - a sublist of the remaining unsorted items that occupy the rest of the list. 
 * 
 * @param arr 
 */
void selectionsort(list lst)
{
  for (size_t i = 0; i < lst.size; i++)
  {
    int min = i;
    for (size_t j = i + 1; j < lst.size; j++)
    {
      if (lst.items[j] < lst.items[min])
      {
        min = j;
      }
    }
    int temp = lst.items[i];
    lst.items[i] = lst.items[min];
    lst.items[min] = temp;
  }
}

/**
 * @brief - performs insertion sort on the provided array or values. 
 * The default sorting mode is ascending
 * 
 * @param lst 
 */
void insertionsort(list lst)
{
  for (size_t i = 1; i < lst.size; i++)
  {
    int key = lst.items[i];
    int j = i - 1;
    while (j >= 0 && lst.items[j] > key)
    {
      //shift the larger values to the right
      lst.items[j + 1] = lst.items[j];
      j -= 1;
    }
    //insert the key - current smallest value at the appropriate position
    lst.items[j + 1] = key;
  }
}

/**
 * @brief - The recursive vesion of the insertion sort.
 * Th recursion just replaces the outer loop, calling itself and storing successively smaller values of n on the stack until n equals 0, 
 * where the function then returns up the call chain to execute the code after each recursive call starting with n equal to 1, 
 * with n increasing by 1 as each instance of the function returns to the prior instance. 
 * The initial call would be recursive_insertionsort(list, length(list)-1). 
 * 
 * @param lst 
 * @param n 
 */
void recursive_insertionsort(list lst, int n)
{
  if (n > 0)
  {
    recursive_insertionsort(lst, n-1);
    int key = lst.items[n];
    size_t j = n - 1;

    while ( j>= 0 && lst.items[j] > key)
    {
      lst.items[j + 1] = lst.items[j];
      j -= 1;
    }
    lst.items[j + 1] = key;
  }
}

/**
 * @brief performs merge sort on the provided array or values. 
 * The default sorting mode is ascending
 * 
 * @param lst 
 */
void mergesort(list lst)
{  
  if (lst.size > 1)
  {
    size_t mid = lst.size/2;
    size_t end = lst.size - mid;
    list sub_list_a;
    list sub_list_b;
    size_t i = 0;

    sub_list_a.size = mid;
    sub_list_a.items = (int*)malloc(sub_list_a.size * sizeof(int));
    sub_list_b.size = end;
    sub_list_b.items = (int*)malloc(sub_list_b.size * sizeof(int));

    for (size_t j = 0; j < sub_list_a.size; j++)
    {
      sub_list_a.items[j] = lst.items[i];
      i += 1;
    }
    for (size_t j = 0; j < sub_list_b.size; j++)
    {
      sub_list_b.items[j] = lst.items[i];
      i += 1;
    }
    
    mergesort(sub_list_a);
    mergesort(sub_list_b);
    merge(lst, sub_list_a, sub_list_b);   
  }
}

/**
 * @brief merges the elements from the sublists to the final list.
 * The merging is done in Linear Time
 * 
 * @param lst 
 * @param sub_list_a 
 * @param sub_list_b 
 */
void merge(list lst, list sub_list_a, list sub_list_b)
{
  size_t a = 0;
  size_t b = 0;

  while ((a + b) < lst.size)
  {
    if (b==sub_list_b.size || (a < sub_list_a.size && sub_list_a.items[a] < sub_list_b.items[b]))
    {
      lst.items[a + b] = sub_list_a.items[a];
      a += 1;
    }
    else
    {
      lst.items[a + b] = sub_list_b.items[b];
      b += 1;
    }
  }
}