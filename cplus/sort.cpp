#include "sort.hpp"

Sort::Sort()
{
}

Sort::~Sort()
{
}

/**
 * @brief performs bubble sort on the provided array of values. 
 * The default sorting mode is ascending.
 * Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements 
 * and then swapping their positions if they exist in the wrong order.
 * 
 * @param v 
 */
void Sort::bubblesort(vector<int> &v) const
{
  auto len = v.size();
  for (int i = 0; i < len; i++)
  {
    bool swapped = false;
   for (int j = 0; j < len - i - 1; j++)
   {
     if (v[j] > v[j + 1])
     {
       this->swap(v, j, j + 1);
       swapped = true;
     }
   }
   //After an iteration, if there is no swapping, the value of swapped will be false:=0. 
   //This means elements are already sorted and there is no need to perform further iterations.
   //This will reduce the execution time and helps to optimize the bubble sort.
   if (!swapped)
   {
     break;
   }
  }
}

/**
 * @brief  performs selection sort on the provided array of values. 
 * The default sorting mode is ascending
 * The algorithm divides the input list into two parts: 
 *  - a sorted sublist of items which is built up from left to right at the front (left) of the list and 
 *  - a sublist of the remaining unsorted items that occupy the rest of the list. 
 * 
 * @param v 
 */
void Sort::selectionsort(vector<int>&v) const
{
  int len = v.size();
  for (int i = 0; i < len; i++)
  {
    int min = i;

    for (int j = i + 1; j < len; j++)
    {
      if (v[j] < v[min] )
      {
        min = j;
      }
    }
    //only swap if new minimum value is found
    if (min != i)
    {
      this->swap(v, i, min);
    }
  }
}

/**
 * @brief performs insertion sort on the provided array of values. 
 * The default sorting mode is ascending
 * The algorithm grows the sorted array/list on each iteration
 * @param v 
 */
void Sort::insertionsort(vector<int>&v) const
{
  int len = v.size();

  for (int i = 1; i < len; i++)
  {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > key)
    {
      //shift the larger values to the right
      v[j + 1] = v[j];
      j -= 1;
    }
    //insert the current smaller value at the right position
    v[j + 1] = key;
  }
}

/**
 * @brief performs insertion sort on the provided array of values. 
 * The default sorting mode is ascending
 * The algorithm grows the sorted array/list on each iteration
 * the recursive part replaced the outer loop of the normal insertion sort
 * 
 * @param v 
 * @param n 
 */
void Sort::recursive_insertionsort(vector<int>&v, int n) const
{
  if (n > 0)
  { 
    this->recursive_insertionsort(v, (n - 1));
    int key = v[n];
    int i = n - 1;
    while (i>=0 && v[i] > key)
    {
      //shift the larger values to the right
      v[i  + 1] = v[i];
      i -= 1;
    }
    //insert the current smaller value at the right position
    v[i + 1] = key;
  }
}

/**
 * @brief performs merge sort on the provided array of values. 
 * The default sorting mode is ascending
 * 
 * @param v 
 */
void Sort::mergesort(vector<int>&v) const
{
  int len = v.size();

  if (len > 1)
  {
    auto mid = std::next(v.begin(), (len/2));
    vector<int>left(v.begin(), mid);
    vector<int>right(mid,v.end());
    
    //sort the left sub array
    this->mergesort(left);
    //sort the right sub array
    this->mergesort(right);
    //merge the sub lists
    this->merge(v, left, right);
  }
}
/**
 * @brief merges the elements from the sublists to the final list.
 * The merging is done in Linear Time
 * 
 * @param v 
 * @param left 
 * @param right 
 */
void Sort::merge(vector<int>&v, vector<int>&left, vector<int>&right) const
{
  int size = v.size();
  int lsize = left.size();
  int rsize = right.size();
  int i = 0;
  int j = 0;

  while (i + j < size)
  {
    if (j == rsize || (i < lsize && left[i] < right[j]))
    {
      v[i + j] = left[i];
      i += 1;
    }
    else
    {
      v[i + j] = right[j];
      j += 1;
    }
  }
  
}

/**
 * @brief generic function that calls the merge sort procedure.
 *  the procedure is the resposible for performing the actual sort
 * 
 * @param v 
 */
void Sort::_mergesort_(vector<int>&v) const
{
  this->_mergesort_procedure_(v, 0, v.size() - 1);
}

/**
 * @brief performs merge sort on the provided array of values. 
 * The default sorting mode is ascending
 * 
 * @param v 
 * @param start 
 * @param end 
 */
void Sort::_mergesort_procedure_(vector<int>&v, int start, int end) const
{
  if (start < end)
  {
    int mid = (start + end)/2;
    this->_mergesort_procedure_(v, start, mid);
    this->_mergesort_procedure_(v, mid + 1, end);
    this->_merge_(v, start, mid, end);
  }
}

/**
 * @brief 
 * 
 * @param v 
 * @param start 
 * @param mid 
 * @param end 
 */
void Sort::_merge_(vector<int>&v, int start, int mid, int end) const
{
  int lsize = mid - start + 1;
  int rsize = end - mid;
  int l = 0;
  int r = 0;
  int k = start;
  vector<int>left;
  left.reserve(lsize);
  vector<int>right;
  right.reserve(rsize);

  for (int i = 0; i < lsize; i++)
  {
    left.push_back(v[i + start]);
  }
  
  for (int i = 0; i < rsize; i++)
  {
    right.push_back(v[i + mid + 1]);
  }
  
  while (l < lsize && r < rsize)
  {
    if(left[l] < right[r])
    {
      v[k] = left[l];
      l += 1;
    }
    else
    {
      v[k] = right[r];
      r += 1;
    }
    k += 1;
  }

  while (l < lsize)
  {
     v[k] = left[l];
     l += 1;
     k += 1;
  }

  while (r < rsize)
  {
     v[k] = right[r];
     r += 1;
     k += 1;
  }
}

/**
 * @brief entry function to the quick sort . It calls the quicksort procedure which is the function 
 * that perfoms the actual quick sort on the provided list/array
 * 
 * @param v 
 */
void Sort::quicksort(vector<int>&v) const
{
  this->quicksort_procedure(v, 0, v.size() - 1);
}


/**
 * @brief performs quick sort on the provided array of values. 
 * The default sorting mode is ascending
 * 
 * @param v 
 * @param start 
 * @param end 
 */
void Sort::quicksort_procedure(vector<int>&v, int start, int end) const
{
  if (start < end)
  {
    int point = this->partition(v, start, end);
    this->quicksort_procedure(v, start, point);
    this->quicksort_procedure(v, point + 1, end); 
  }
}

/**
 * @brief parttions the array such that the smallest values are always at the left side
 * of the pivot with the larger values to the right of the pivot
 * 
 * @param v 
 * @param start 
 * @param end 
 * @return int 
 */
int Sort::partition(vector<int>&v, int start, int end) const
{
  int pivot = this->median_of_three(v, start, end);
  while (true)
  {
    while (v[start] < v[pivot])
    {
      start += 1;
    }
    while (v[end] > v[pivot])
    {
      end -= 1;
    }
    
    if (start >= end)
    {
      return end;
    }
    //perform the swapp
    this->swap(v, start, end);

    start += 1;
    end -= 1;
  }

  //return a bad value if the correct partition point is not found
  //this can only happen if our implementation is wrong
  return -1;
}

/**
 * @brief 
 * 
 * @param v 
 */
void Sort::countsort(vector<int> &v) const
{
  int len = v.size();
  int max = *max_element(v.begin(), v.end());
  vector<int> aux(len);
  vector<int>count(max + 1);

  //compute the frequencies of the unique values in v
  for (int i = 0; i < len; i++)
  {
    count[v[i]] += 1;
  }

  //commulative of the frequencies -  which represents the actual position of the elements in the sorted array/list
  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1]; 
  }

  // build sorted array
  for (int i = len - 1; i>=0; i--)
  {
    aux[--count[v[i]]] = v[i];
  }
  
  //copy back the sorted array
  v = aux;
}

/**
 * @brief performs radix sort on the provided array of values.
 * The default sorting mode is ascending
 *
 * @param v
 */
void Sort::radixsort(vector<int>&v) const
{
  int len = v.size();
  int max = *max_element(v.begin(), v.end());
  int digits = this->getdigits(max);
  int pos = 1;

  for (int i = 0; i < digits; i++)
  {
    this->radix_countsort(v, len, pos);
    pos*=10;
  }
}

/**
 * @brief performs the actual sort which is consumed by the radix sort
 * 
 * @param v 
 * @param len 
 * @param pos 
 */
void Sort::radix_countsort(vector<int>&v, int len, int pos) const
{
  vector<int>aux(len);
  vector<int>count(10);
  
  //the frequency counts
  for (int i = 0; i < len; i++)
  {
    count[((v[i] / pos) % 10)] += 1;
  }
  
  //commulative counts
  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i -1];
  }
  
  //build sorted array
  for (int i = len - 1; i >= 0; i--)
  {
    aux[--count[((v[i] / pos) % 10)]] = v[i];
  }

  // copy back the sorted array
  v = aux;
}

/**
 * @brief performs heap sort on the provided array of values.
 * The default sorting mode is ascending
 *
 * @param v
 */
void Sort::heapsort(vector<int> &v) const
{
  //build the maxheap
  int len = v.size();
  this->buildmaxheap(v, len);

  //call the heapify function after swapping the values to maintain the max-heap properties
  for (int i = len - 1; i >= 0; i--)
  {
    this->swap(v, 0, i);
    this->maxheapify(v, i - 1, 0);
  }
}

/**
 * @brief corrects the heap property if any violation occurs
 * 
 * @param v 
 * @param len 
 * @param i 
 */
void Sort::maxheapify(vector<int> &v, int len, int i) const
{
  int j = i;
  int l = 2 * i;
  int r = (2 * i) + 1;

  if (l <= len && v[l] > v[j])
  {
    j = l;
  }
  if (r <= len && v[r] > v[j])
  {
    j = r;
  }

  if (i != j)
  {
    this->swap(v, i, j);
    this->maxheapify(v, len, j);
  }
}

/**
 * @brief builds the max heap that satisfies the a maxheap data structure
 *
 * @param v
 */
void Sort::buildmaxheap(vector<int> &v, int len) const
{
  for (int i = (len / 2); i >= 0; i--)
  {
    this->maxheapify(v, len - 1, i);
  }
}


/**
 * @brief compute the number of digits that constitutes the list
 * 
 * @param max 
 * @return int 
 */
int Sort::getdigits(int max) const
{
  int digits = 0;
  while (max !=0)
  {
    max /= 10;
    digits += 1;
  }
  return digits;
}

/**
 * @brief computes the median of the three values
 * - which are presented by the parameters: start, end, and (start+end)/2
 *
 * @param v
 * @param start
 * @param end
 * @return int
 */
int Sort::median_of_three(vector<int> &v, int start, int end) const
{
  int mid = (start + end)/2;
  int x = v[mid] - v[start];
  int y = v[start] - v[end];
  int z = v[mid] - v[end];

  return (x*y > 0 ? start: (x*z > 0 ? end : mid));
}

/**
 * @brief performs swap on the list by swapping the elements at the specified indices - i and j
 * 
 * @param list 
 * @param a 
 * @param b 
 */
void Sort::swap(vector<int> &v, int i, int j) const
{
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
