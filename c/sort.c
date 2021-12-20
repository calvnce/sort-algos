#include "sort.h"

/**
 * @brief performs bubble sort on the provided array or values.
 * the default sorting mode is ascending
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