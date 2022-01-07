package labs.sort;
import java.util.Arrays;

public class Sort {
    /**
     *   performs bubble sort on the provided array of values.
     *
     *   The default sorting mode is ascending.
     *
     *   Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements
     *   and then swapping their positions if they exist in the wrong order.
     * @param arr - array to be sorted
     */
    public  void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            boolean isSwapped = false;
            for (int j = 0; j < arr.length - i -1; j++) {
                if (arr[j] > arr[j + 1]) {
                    this.swap(arr, j, j+1);
                    isSwapped = true;
                }
            }
            /*
               After an iteration, if there is no swapping, the value of swapped will be false.
               This means elements are already sorted and there is no need to perform further iterations.
               This will reduce the execution time and helps to optimize the bubble sort.
            */
            if (!isSwapped) {
                break;
            }
        }
    }
    
    /**
     *  performs selection sort on the provided array of values.
     *  The default sorting mode is ascending
     *  The algorithm divides the input list into two parts:
     *   - a sorted sublist of items which is built up from left to right at the front (left) of the list and
     *   - a sublist of the remaining unsorted items that occupy the rest of the list.
     * @param arr - array to be sorted
     */
    public  void selectionSort(int[] arr) {
        for (int i = 0; i <arr.length; i++) {
            int min = i;
            for (int j = i +1; j < arr.length; j++) {
                //look for the next minimum within the remaining array
                if (arr[j] < arr[min])
                    min = j;
            }
            //if the new minimum is found, then swap
            if (min != i)
                this.swap(arr, i, min);
        }
    }

    /**
     *  performs insertion sort on the provided array of values.
     *  The default sorting mode is ascending
     *  The algorithm grows the sorted array/list on each iteration
     * @param arr - array to be sorted
     */
    public  void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            this.insertionSortProcedure(arr, i);
        }
    }

    /**
     * performs insertion sort on the provided array of values. 
     * The default sorting mode is ascending 
     * The algorithm grows the sorted array/list on each iteration
     * 
     * @param arr - array to be sorted
     * @param i - length of the array - used to track the outer loop
     */
    public void insertionSort(int[] arr, int i) {
        if (i > 0) {
            this.insertionSort(arr, i-1);
            this.insertionSortProcedure(arr, i);
        }
    }

    /**
     *  Performs the actual insertion sort procedure.
     * @param arr - array to be sorted
     * @param i - index
     */
    private void insertionSortProcedure(int[] arr, int i) {
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] > key) {
            arr[j +1] = arr[j];
            j -= 1;
        }
        arr[j +1] = key;
    }

    /**
     *  performs merge sort on the provided array of values.
     *  The default sorting mode is ascending
     * @param arr - array to be sorted
     */
    public  void mergeSort(int[] arr) {
        if (arr.length > 1) {
            int mid = arr.length/2;
            //split the array into left and right
            int[] left = new int[mid];
            int[] right = new int[arr.length - mid];
            System.arraycopy(arr, 0, left, 0, left.length);
            System.arraycopy(arr, mid, right, 0, right.length);
            //sorts the left sub-array
            this.mergeSort(left);
            //sorts the right sub-array
            this.mergeSort(right);
            //merge the sorted sub-arrays
            this.merge(arr,  left, right) ;
        }
    }

    /**
     *  performs merge sort on the provided array of values.
     *  The default sorting mode is ascending
     * @param arr  - array to be sorted
     * @param start - index
     * @param end - index
     */
    public void mergeSort(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end)/2;
            this.mergeSort(arr, start, mid);
            this.mergeSort(arr, mid + 1, end);
            this.merge(arr, start, mid, end);
        }
    }

    /**
     *   merges the elements from the sub arrays to the final array.
     *   The merging is done in Linear Time
     * @param arr -  array to be sorted
     * @param start - index
     * @param mid - index
     * @param end - index
     */
    private void merge(int[] arr, int start, int mid, int end) {
        int l = 0;
        int r = 0;
        int k = start;
        //split the array into sub-arrays
        int[] left = new int[mid - start + 1];
        int[] right  = new int[end - mid];
        //fill the sub arrays
        for (int i = 0; i < left.length; i++) {
            left[i] = arr[start + i];
        }
        for (int i = 0; i < right.length; i++) {
            right[i] = arr[mid + i + 1];
        }

        // sort the sub-arrays
        while (l < left.length &&  r < right.length) {
            if (left[l] < right[r]) {
                arr[k] = left[l];
                l+=1;
            }
            else {
                arr[k] = right[r];
                r+=1;
            }
            k += 1;
        }

        // copy back the remaining left sub-array
        while (l < left.length) {
            arr[k] = left[l];
            l+=1;
            k += 1;
        }
        // copy back the remaining right sub-array
        while (r < right.length) {
            arr[k] = right[r];
            r+=1;
            k += 1;
        }
    }

    /**
     *  merges the elements from the sub arrays to the final array.
     *  The merging is done in Linear Time
     * @param arr - array to be sorted
     * @param left - left sub-array
     * @param right - right sub-array
     */
    private void merge(int[] arr, int[] left, int[] right) {
        int l =0;
        int r = 0;
        while (l + r < arr.length) {
            if (r == right.length || (l < left.length && left[l] < right[r])) {
                arr[l +r] = left[l];
                l +=1 ;
            }
            else   {
                arr[l +r] = right[r];
                r +=1 ;
            }
        }
    }

    /**
     *  entry function to the quick sort . It calls the quicksort procedure which is the function
     *  that performs the actual quick sort on the provided list/array
     * @param arr - array to be sorted
     */
    public  void   quickSort(int[] arr) {
        this.quickSortProcedure(arr, 0, arr.length - 1);
    }

    /**
     *  performs quick sort on the provided array of values.
     *  The default sorting mode is ascending
     * @param arr - array to be sorted
     * @param start  - index
     * @param end - index
     */
    private void quickSortProcedure(int[] arr, int start, int end) {
        if (start < end) {
            int point = this.partition(arr, start, end);
            this.quickSortProcedure(arr, start, point);
            this.quickSortProcedure(arr, point + 1, end);
        }
    }

    /**
     *  partitions the array such that the smallest values are always on the left side
     *  of the pivot with the larger values to the right of the pivot
     * @param arr - array to be sorted
     * @param start - index
     * @param end - index
     * @return  - partition point : index
     */
    private int partition(int[] arr, int start, int end) {
        int pivot = this.median(arr, start, end);
        while (true) {
            while (arr[start] < arr[pivot]) {
                start += 1;
            }
            while (arr[end] > arr[pivot]) {
                end -= 1;
            }
            if (start >= end)
                return end;
            //swap
            this.swap(arr, start, end);
            start += 1;
            end -= 1;
        }
    }

    /**
     *  performs count sort on the provided array of values.
     *  The default sorting mode is ascending
     * @param arr - array to be sorted
     */
    public void  countSort(int[] arr) {
        //largest value in the array
        int max = Arrays.stream(arr).max().orElse(0);
        //auxiliary array temporarily store the sorted array
        int[] aux = new int[arr.length];
        //counts array for storing the unique elements frequencies
        int[] count  =new int[max + 1];
        //initialize the counts with zeros
        Arrays.fill(count, 0);

        //get the frequencies
        for (int item: arr ) {
            count[item]+=1;
        }
        //cumulative sums of the frequencies
        for (int i = 1; i < count.length; i++) {
            count[i] += count[i - 1];
        }

        //build the sorted array
        for (int i = arr.length - 1; i >= 0; i--) {
            aux[--count[arr[i]]] = arr[i];
        }
        //copy the sorted array back
        System.arraycopy(aux, 0, arr, 0, arr.length);
    }

    /**
     *  performs radix sort on the provided array of values.
     *  The default sorting mode is ascending
     * @param arr - array to be sorted
     */
    public void radixSort(int[] arr) {
        //largest value in the array
        int max = Arrays.stream(arr).max().orElse(0);
        //number of digits
        int digits = getDigits(max);
        //position of the digit being traced
        int pos = 1;

        //perform the sort
        for (int i = 0; i < digits; i++) {
            this.radixCountSort(arr, pos);
            pos *= 10;
        }
    }

    /**
     *  performs the actual sort which is consumed by the radix sort
     * @param arr - array to be sorted
     * @param pos - digit being considered
     */
    private void radixCountSort(int[] arr, int pos) {
        //auxiliary array temporarily store the sorted array
        int[] aux = new int[arr.length];
        //counts array for storing the unique elements frequencies
        int[] count  =new int[10];
        //initialize the counts with zeros
        Arrays.fill(count, 0);

        //get the frequencies
        for (int item : arr) {
            count[((item/pos)%10)] += 1;
        }
        //cumulative sums of the frequencies
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        //build the sorted array
        for (int i = arr.length - 1; i >= 0; i--) {
            aux[--count[((arr[i]/pos)%10)]] = arr[i];
        }

        //copy the sorted array back
        System.arraycopy(aux, 0, arr, 0, arr.length);
    }

    /**
     *   performs heap sort on the provided array of values.
     *   The default sorting mode is ascending
     * @param arr  - array to be sored
     */
    public  void heapSort(int[] arr) {
        //build the max heap
        this.buildMaxHeap(arr, arr.length);
        //perform the sort
        for (int i = arr.length - 1; i >= 0; i--) {
            this.swap(arr, 0, i);
            this.maxHeapify(arr, i - 1, 0);
        }
    }

    /**
     *  builds the max heap that satisfies a maxheap data structure
     * @param arr - array to be sorted
     * @param length - length of the array
     */
    private void buildMaxHeap(int[] arr, int length) {
        for (int i = length/2; i >= 0; i--) {
            this.maxHeapify(arr, length - 1, i);
        }
    }

    /**
     *  corrects the heap property if any violation occurs
     * @param arr - array to be corrected
     * @param length - length of the array
     * @param i - index
     */
    private void maxHeapify(int[] arr, int length, int i) {
        int largest = i;
        int l = i*2;
        int r  = i*2 + 1;
        if (l <= length && arr[l] > arr[largest])
            largest = l;
        if (r <= length && arr[r] > arr[largest])
            largest = r;
        if (largest != i) {
            this.swap(arr, i, largest);
            this.maxHeapify(arr, length, largest);
        }
    }

    /**
     *  computes the number of digits which constitutes the provided number
     * @param max  - value whose digits are being counted
     * @return  - number of digits : digits
     */
    private int getDigits(int max) {
        int digits = 0;
        while (max != 0) {
            max /= 10;
            digits += 1;
        }
        return digits;
    }

    /**
     *  computes the median of the three values specified by the params - start, end and (start +end)/2
     * @param arr - array containing three values
     * @param start  - index
     * @param end - index
     * @return - median index
     */
    private int median(int[] arr, int start, int end) {
        int mid = (start+ end)/2;
        int x = arr[mid] - arr[start];
        int y = arr[start] - arr[end];
        int z= arr[mid] - arr[end];

        return (x*y > 0 ? start : (x*z > 0 ? end : mid));
    }

    /**
     * performs swap of the two array values represented by the params: i and j
     * @param arr - array containing values to be swapped
     * @param i - index
     * @param j - index
     */
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
