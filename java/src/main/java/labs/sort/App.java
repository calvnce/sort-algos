package labs.sort;

import java.util.Random;

/**
 * This class contains the main method
 *
 */
public class App 
{
    public static void main( String[] args )
    {
        //Instantiate Sort object
        Sort sort = new Sort();
        //Generate random numbers
        Random random = new Random();
        int length = 9999;
        int[] arr = new int[length];
        for (int i = 0; i <length; i++) {
            arr[i] = random.nextInt(999);
        }

        //show the unsorted array
        for (int i = 0; i <length; i++) {
            if (i != 0 && i%45 ==0)
                System.out.println();
            System.out.printf("%d  ", arr[i]);
        }
        System.out.println("\n\n");

        /*
         BUBBLE SORT
          sort.bubbleSort(arr);

         SELECTION SORT
          sort.selectionSort(arr);

         INSERTION SORT
          sort.insertionSort(arr);
          sort.insertionSort(arr, length - 1);

          MERGE SORT
          sort.mergeSort(arr);
          sort.mergeSort(arr, 0, length - 1);

          QUICK SORT
          sort.quickSort(arr);

          COUNT SORT
          sort.countSort(arr);

          RADIX SORT
          sort.radixSort(arr);

          HEAP SORT
           sort.heapSort(arr);
        */
        sort.heapSort(arr);

        for (int i = 0; i <length; i++) {
            if (i != 0 && i%40 ==0)
                System.out.println();
            System.out.printf("%d  ", arr[i]);
        }
        System.out.println("\n");
    }
}
