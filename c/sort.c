#include "sort.h"

/**
 * @brief performs bubble sort on the provided array or values. 
 * The default sorting mode is ascending.
 * Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements 
 * and then swapping their positions if they exist in the wrong order. 
 * 
 * @param arr 
 */
void bubble_sort(int* arr)
{
  size_t len = arr[0];
  
  for (size_t i = 1; i < len; i++)
  {
    int swapped = 0;
    for (size_t j = 1; j < len - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j+1] = temp;
        
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
void selection_sort(int *arr)
{
  size_t len = arr[0];
  size_t i = 1;
  size_t j;

  while (i < len)
  {
    // assume the first element in the array is the minimum */
    int min = i;

    for (j = i + 1; j < len; j++)
    {
      // if this element is less, then it is the new minimum */
      if (arr[j] < arr[min])
      {
        //we have discovered the index pointing our new minimum
        min = j;
      }
    }
    //only perform swap if the new minimum was found. 
    //This ensures that our sorting procedure is stable
    if (min != i)
    {
      //swap the values and place the values at their appropriate locations
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
    }
    //increment i
    i+=1;
  }
}