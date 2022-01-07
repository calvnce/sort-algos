
namespace SoringAlgorithms;

public class Sort
{
  public Sort()
  {}

 /// <summary>
 /// performs bubble sort on the provided array of values.The default sorting mode is ascending.
 /// Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements
 /// and then swapping their positions if they exist in the wrong order.
 /// </summary>
 /// <param name="arr"></param>
  public void BubbleSort(int[] arr)
  {
    for (int i = 0; i < arr.Length; i++)
    {
      bool isSwapped = false; 
      for (int j = 0; j < arr.Length - i - 1; j++)
       {
         if (arr[j] > arr[j + 1])
         {
           this.Swap(arr, j, j+1);
           isSwapped = true;
         }
      }
      //exit the loop if no swap was made. Indicating that the array is already sorted
      if(!isSwapped)
      {
       break;
      }
    }
  }

  /// <summary>
  /// performs selection sort on the provided array of values. 
  ///  The default sorting mode is ascending
  /// The algorithm divides the input list into two parts: 
  ///  - a sorted sublist of items which is built up from left to right at the front(left) of the list and 
  /// - a sublist of the remaining unsorted items that occupy the rest of the list.
  /// </summary>
  /// <param name="arr"></param>
  public void SelectionSort(int[] arr)
  {
    for (int i = 0; i < arr.Length; i++)
    {
      int min = i;
      for (int j = (i + 1) ; j <arr.Length; j++)
      {
        if(arr[j] < arr[min])
        {
          min = j;
        }
      }
      //swap the vaules if the current value is the minimum
      if (i != min)
      {
        this.Swap(arr, i, min);
      }
    }
  }

  /// <summary>
  /// performs insertion sort on the provided array of values. 
  /// The default sorting mode is ascending
  // The algorithm grows the sorted array/list on each iteration
  /// </summary>
  /// <param name="arr"></param>
  public void InsertionSort(int[] arr)
  {
   for (int i = 1; i < arr.Length; i++)
   {
     int key = arr[i];
     int j = i - 1;

     while (j >=0 && arr[j] > key)
     {
        //shift the larger values to the right
        arr[j + 1] = arr[j];
       j -= 1;
     }

     //insert the new minimum at the right position
     arr[j + 1] = key;
   }
  }

  /// <summary>
  /// performs insertion sort on the provided array of values. 
  /// The default sorting mode is ascending
  /// The algorithm grows the sorted array/list on each iteration
  /// 
  /// The recursive part replaced the outer loop of the normal insertion sort
  /// </summary>
  /// <param name="arr"></param>
  /// <param name="i"></param>
  public void RecursiveInsertionSort(int[] arr, int i)
  {
    if (i > 0)
    {
      this.RecursiveInsertionSort(arr, i - 1);
      int key = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > key)
      {
        arr[j + 1] = arr[j];
        j -= 1;
      }
      arr[j + 1] = key;
    }
  }

  /// <summary>
  /// performs merge sort on the provided array of values. 
  /// The default sorting mode is ascending
  /// </summary>
  /// <param name="arr"></param>
  public void MergeSort(int[] arr)
 {
   int Length = arr.Length;
   if (Length > 1)
   {
    int Mid = Length/2;
    int[] left = arr.Take(Mid).ToArray();
    int[] right = arr.Skip(Mid).ToArray();

    this.MergeSort(left);
    this.MergeSort(right);
    this.Merge(arr, Length, left, left.Length,  right, right.Length);
   }
  }

  /// <summary>
  ///  merges the sublist back into the sorted list
  /// </summary>
  /// <param name="arr">array to be sorted</param>
  /// <param name="Length">Size of the original array</param>
  /// <param name="left">left sub array</param>
  /// <param name="L"> Size of the left sub array</param>
  /// <param name="right">right sub array</param>
  /// <param name="R">Size of the Right sub array</param>
  private void Merge(int[] arr, int Length, int[] left, int L, int[] right, int R)
  {
    int i = 0;
    int j = 0;

    while(i + j < Length)
    {
      if (j == R || (i < L && left[i] < right[j]))
      {
       arr[i + j] = left[i];
       i += 1;
      }
      else
      {
        arr[i + j] = right[j];
        j += 1;
      }
    }
  }

 /// <summary>
 /// performs merge sort on the provided array of values. 
 /// The default sorting mode is ascending
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="start"></param>
 /// <param name="end"></param>  
 public void MergeSort(int[] arr, int start, int end)
  {
    if(start < end)
    {
      int mid = (start + end) / 2;
      this.MergeSort(arr, start, mid);
      this.MergeSort(arr, mid + 1, end);
      this.Merge(arr, start, mid, end);
    }
 }

 /// <summary>
 /// performs merge sort on the provided array of values. 
 /// The default sorting mode is ascending
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="start"></param>
 /// <param name="mid"></param>
 /// <param name="end"></param>
 private void Merge(int[] arr, int start, int mid, int end)
 {
   int L = (mid - start) + 1;
   int R = end - mid;
   int l = 0;
   int r = 0;
   int k = start;

   //sub arrays
   int[] left = new int[L];
   int[] right = new int[R];

   //fill the sub arrays
   for (int i = 0; i < L; i++)
   {
     left[i] = arr[start + i];
   }
   for (int i = 0; i < R; i++)
   {
     right[i] = arr[mid + i + 1];
   }

   //sort the arrays
   while (l < L && r < R)
   {
     if (left[l] < right[r])
     {
       arr[k] = left[l];
       l += 1;
     }
     else
     {
       arr[k] = right[r];
       r += 1;
     }
     k += 1;
   }

   while (l < L)
   {
     arr[k] = left[l];
     l += 1;
     k += 1;
   }
   while (r < R)
   {
     arr[k] = right[r];
     r += 1;
     k += 1;
   }
 }

/// <summary>
/// entry function to the quick sort . It calls the quicksort procedure which is the function 
/// that perfoms the actual quick sort on the provided list/array
/// </summary>
/// <param name="arr"></param>
 public void QuickSort(int[] arr)
 {
   this.QuickSortProcedure(arr, 0, arr.Length - 1);
 }

 /// <summary>
 /// performs quick sort on the provided array of values. 
 /// The default sorting mode is ascending
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="start"></param>
 /// <param name="end"></param>
 private void QuickSortProcedure(int[] arr, int start, int end)
 {
   if(start < end)
   {
     int point = this.Partition(arr, start, end);
     this.QuickSortProcedure(arr, start, point);
     this.QuickSortProcedure(arr, point + 1, end);
   }
 }

 /// <summary>
 /// parttions the array such that the smallest values are always at the left side
 /// of the pivot with the larger values to the right of the pivot
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="start"></param>
 /// <param name="end"></param>
 /// <returns></returns>
 private int Partition(int[] arr, int start, int end)
 {
   int pivot = this.ThreeMedian(arr, start, end);
   while(true)
   {
     while(arr[start] < arr[pivot])
     {
       start += 1;
     }
     while (arr[end] > arr[pivot]) 
     {
       end -= 1;
     }
     if (start >= end) 
     {
       return end;
     }
     Swap(arr, start, end);
     start += 1;
     end -= 1;
   }
 }
 
 /// <summary>
 /// 
 /// </summary>
 /// <param name="arr"></param>
 public void CountSort(int[] arr)
 {
   int max = arr.Max();
   int Length = arr.Length;
   //holds the values of the sorted array
   int[] aux = new int[Length];
   //holds the frequency of the unque values
   int[] count = new int[max + 1];

   //compute the frequencies
   foreach (var item in arr)
   {
     count[item]+=1;
   }

   //cummulative of the frquencies - represents the final location of the elements 
   //in the sorted array
   for (int i = 1; i <= max; i++)
   {
     count[i] += count[i - 1];
   }

  //build final sorted array
  for (int i = Length - 1; i >= 0; i--)
  {
   aux[--count[arr[i]]] = arr[i];
  }
  
   //copy back sorted array
   Array.Copy(aux,arr,Length);
 }

 /// <summary>
 /// performs radix sort on the provided array of values.
 /// The default sorting mode is ascending
 /// </summary>
 /// <param name="arr"></param>
 public void RadixSort(int[] arr)
 {
  //largest value in the array
  int max = arr.Max();
  //number of digits making the largest value
  int digits = this.GetDigits(max);
  int Length = arr.Length;
  //tracks the current position of the values being compared
  int pos = 1;

  //perform the sort by calling the count sort 
  for (int i = 0; i < digits; i++)
  {
    this.RadixCountSort(arr, Length, pos);
    pos *= 10;
  }
 }

 /// <summary>
 /// performs the actual sort which is consumed by the radix sort
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="Length"></param>
 /// <param name="pos"></param>
 private void RadixCountSort(int[] arr, int Length, int pos)
 {
  //holds the values of the sorted array
  int[] aux = new int[Length];
  //holds the frequency of the unque values
  int[] count = new int[10];

  //compute the frequencies
  foreach (var item in arr)
  {
    count[((item/pos)%10)]+=1;
  }

  //cummulative of the frquencies - represents the final location of the elements 
  //in the sorted array
  for (int i = 1; i < 10; i++)
  {
    count[i] += count[i - 1]; 
  }

  //build final sorted array
  for (int i = Length - 1; i >= 0 ; i--)
  {
   aux[--count[((arr[i] / pos) % 10)]] = arr[i];
  }

  //copy back sorted array
  Array.Copy(aux, arr, Length);
 }


  /// <summary>
  /// 
  /// </summary>
  /// <param name="arr"></param>
  public void HeapSort(int[] arr)
  {
    int Length = arr.Length;
    //build the max-heap
    this.BuildMaxHeap(arr, Length);
    //sort
    for (int i = Length - 1; i >= 0 ; i--)
    {
      this.Swap(arr,0,i);
      this.MaxHeapify(arr, i - 1, 0);
    }
  }

  /// <summary>
  /// Builds a heap that conforms to a max-heap
  /// </summary>
  /// <param name="arr"></param>
  /// <param name="length"></param>
 private void BuildMaxHeap(int[] arr, int length)
 {
  for (int i = (length / 2); i >= 0 ; i--)
  {
    this.MaxHeapify(arr, length - 1, i);      
  }
 }

 /// <summary>
 /// corrects the heap property if any violation occurs
 /// This procedure makes use of the selection sort
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="Length"></param>
 /// <param name="i"></param>
 private void MaxHeapify(int[] arr, int Length, int i)
 {
  //current largest node element
  int largest = i;
  //left child node
  int left = i * 2;
  //right child node
  int right = i * 2 + 1;

  if (left <= Length && arr[left] > arr[largest])
  {
   largest = left;
  }
  if (right <= Length && arr[right] > arr[largest])
  {
   largest = right;
  }
  
  if (i != largest)
  {
    this.Swap(arr, i, largest);
    this.MaxHeapify(arr, Length, largest);
  }
 }

 /// <summary>
 /// Computes the number of digits that makes up the provided param value
 /// </summary>
 /// <param name="max"></param>
 /// <returns></returns>
 private int GetDigits(int max)
 {
  int digits = 0;
  while (max != 0)
  {
      max /= 10;
    digits += 1;
  }
  
  return digits;
 }

 /// <summary>
 /// computes the median of the three values
 /// - which are presented by the parameters: start, end, and(start+end)/2
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="start"></param>
 /// <param name="end"></param>
 /// <returns></returns>
 private int ThreeMedian(int[] arr, int start, int end)
 {
   int mid = (start + end)/2;
   int x = arr[mid] - arr[start];
   int y = arr[start] - arr[end];
   int z = arr[mid] - arr[end];

   return (x * y > 0 ? start : (x * z > 0 ? end : mid));
 } 

 /// <summary>
 /// swaps the arr values specified by the param indices
 /// </summary>
 /// <param name="arr"></param>
 /// <param name="i"></param>
 /// <param name="j"></param>
 private void Swap(int[] arr, int i, int j)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}