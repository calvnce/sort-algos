#include "sort.h"

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
        swap(lst, j, j+1);
        
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
    swap(lst, i, min);
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

/**
 * @brief This ersion of merge sort uses another approach - which is the most comonly used method
 * to implement the merge sort algorithm.
 * 
 * @param lst 
 */
void merge_sort(list lst)
{
  mergesort_procedure(lst, 0, lst.size - 1);
}

void mergesort_procedure(list lst, size_t start, size_t end)
{
  if (start < end)
  {
    size_t mid = (start + end)/2;
    mergesort_procedure(lst, start, mid);
    mergesort_procedure(lst, mid + 1, end);
    _merge_(lst, start, mid, end);
  }
  
}
void _merge_(list lst, size_t start, size_t mid, size_t end)
{
  list sub_list_a;
  list sub_list_b;
  size_t i;
  size_t a = 0;
  size_t b = 0;
  sub_list_a.size = (mid - start + 1);
  sub_list_b.size = end - mid;
  sub_list_a.items = (int *)malloc(sub_list_a.size * sizeof(int));
  sub_list_b.items = (int *)malloc(sub_list_b.size * sizeof(int));

  //fill sub list a
  for (; a < sub_list_a.size; a++)
  {
    sub_list_a.items[a] = lst.items[start + a];
  }
  //fill the sub list b
  for (; b <  sub_list_b.size; b++)
  {
    sub_list_b.items[b] = lst.items[mid + b + 1];
  }

  //reset the index trackers
  b = a = 0;
  i = start;

  //merge the sublists into the final sorted list
  while (a < sub_list_a.size && b < sub_list_b.size)
  {
    if (sub_list_a.items[a] < sub_list_b.items[b])
    {
      lst.items[i] = sub_list_a.items[a];
      a += 1;
    }
    else
    {
      lst.items[i] = sub_list_b.items[b];
      b += 1;
    }   
    i += 1;
  }

  for (; a < sub_list_a.size; a++)
  {
    lst.items[i] = sub_list_a.items[a];
    i += 1;
  }
  for (; b < sub_list_b.size; b++)
  {
    lst.items[i] = sub_list_b.items[b];
    i += 1;
  }
}

/**
 * @brief performs quick sort on the provided array or values. 
 * The default sorting mode is ascending
 * 
 * @param lst 
 */
void quicksort(list lst)
{
  quicksort_procedure(lst, 0, lst.size - 1);
}

/**
 * @brief this is a recursive function that performs the actual sorting procedure
 * 
 * @param lst 
 * @param start 
 * @param end 
 */
void quicksort_procedure(list lst, size_t start, size_t end)
{
  if (start < end)
  {
    size_t partition_point = partition(lst, start, end);
    quicksort_procedure(lst,start, partition_point);
    quicksort_procedure(lst, partition_point + 1, end);
  }
}
/**
 * @brief performs the hoare partition on the list.
 * it iterates from both ends at once towards the center
 * 
 * @param lst 
 * @param start 
 * @param end 
 * @return int 
 */
int partition(list lst, size_t start, size_t end)
{
  size_t pivot = median_of_three(lst, start, end);
  while (1)
  {
   while (lst.items[start] < lst.items[pivot])
   {
     start += 1;
   }
   while (lst.items[end] > lst.items[pivot])
   {
     end -= 1;
   }

   if (start >= end)
   {
     return end;
   }
   
   //perform the swap 
   swap(lst, start, end);
   start += 1;
   end -=1;
  }
  //return a bad value if the correct partition point is not found
  //this can only happen if our implementation is wrong
  return -1;
}

/**
 * @brief finds the median of the three bound values to be used as the pivot
 * 
 * @param lst 
 * @param start 
 * @param end 
 * @return int 
 */
int median_of_three(list lst, size_t start, size_t end)
{
  size_t mid = (end+ start)/2;
  int x = lst.items[mid] - lst.items[start];
  int y = lst.items[start] - lst.items[end];
  int z = lst.items[mid] - lst.items[end];

  return (x*y > 0 ? start : (x*z > 0 ? end : mid));
}

void countsort(list lst)
{
  //find the maximum element within the array
  int max = getmax(lst);
  //an auxilary array
  int aux[lst.size];
  //frequency of the unique elements
  int counts[max + 1];

  // fill the counts array with  zeros
  memset(counts, 0, sizeof(int)*(max + 1)); 

  //get the frequency of the distinct elements in the unsorted list
  for (int i = 0; i <lst.size; i++)
  {
    counts[lst.items[i]] += 1;
  }

  //comulative sum of the counts
  for (int i = 1; i <= max; i++)
  {
    counts[i] += counts[i - 1];
  }
 
  //get the sorted list by placing the elements from the original list
  //into their correct positions in the aux array
  for (int i = lst.size - 1; i >-1 ; i--)
  {
    aux[--counts[lst.items[i]]] = lst.items[i];
  }

  //final sortes list
  for (int i = 0; i < lst.size; i++)
  {
    lst.items[i] = aux[i]; 
  }
}

/**
 * @brief finds the maximum or largest element within the provided list/array
 * 
 * @param lst 
 * @return int 
 */
int getmax(list lst)
{
  int max = INT_MIN;
  for (int i = 0; i < lst.size; i++)
  {
    if (max < lst.items[i])
    {
      max = lst.items[i];
    }
  }
  return max;
}

/**
 * @brief performs a generic swap of the two values a and b
 * 
 * @param lst 
 * @param a 
 * @param b 
 */
void swap(list lst, size_t a, size_t b)
{
  int temp = lst.items[a];
  lst.items[a] = lst.items[b];
  lst.items[b] = temp;
}