using SoringAlgorithms;

namespace App;
public class Program
{
  public static void Main(string []args)
  {
    //Sort Object Instance
    Sort sort = new Sort();

    int Length = 9999999;
    int[] arr = new int[Length];

    //generate random numbers
    Random rnd = new Random();
    for (int i = 0; i < Length; i++)
    {
      arr[i] = rnd.Next(0, 9999);
    }

    //print unsorted
    for (int i = 0; i <Length; i++)
    {
      if (i % 20 == 0 && i != 0) 
      {
       Console.WriteLine();
      } 
      Console.Write("{0,3}   ", arr[i]);
    }
    Console.WriteLine("\n\n\n");

    //BUBBLE SORT
    // sort.BubbleSort(arr);

    //SELECTION SORT
    // sort.SelectionSort(arr);

    //INSERTION SORT
    // sort.InsertionSort(arr);
    // sort.RecursiveInsertionSort(arr, Length - 1);

    //MERGE SORT
    // sort.MergeSort(arr);
    // sort.MergeSort(arr, 0, Length - 1);

    //QUICK SORT
    // sort.QuickSort(arr);

    //COUNT SORT
    sort.CountSort(arr);

    //RADIX SORT
    // sort.RadixSort(arr);

    //HEAP SORT
    // sort.HeapSort(arr);



    //print sorted
    for (int i = 0; i < Length; i++)
    {
      if (i % 20 == 0 && i != 0)
      {
        Console.WriteLine();
      }
      Console.Write("{0,3}   ", arr[i]);
    }
    Console.WriteLine("\n");
  }
}


