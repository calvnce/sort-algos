class Sort {
  /**
   * Performs the bubble sort on the provided list. 
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  bubbleSort = (list) =>{
    for (let i = 0; i < list.length; i++) {
      let isSwapped = false;
      for (let j = 0; j < list.length - i  - 1; j++) {
        if(list[j] > list[j + 1]) {
          this.swap(list, j, (j + 1))
          isSwapped = true;
        }
      }
      if (!isSwapped) {
        break;
      }
    }
  }

  /**
   * Performs the selection sort sort on the provided list. 
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  selectionSort = (list)=> {
    for (let i = 0; i < list.length; i++) {
      let min = i;
      for (let j = i + 1; j < list.length; j++) {
        if(list[min] > list[j]) {
          min = j;
        }
      }
      if (min != i) {
        this.swap(list, i, min);
      }
    } 
  }

  /**
   * Performs the insertion sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  insertionSort = (list) =>{
    for (let i = 1; i < list.length; i++) {
      const key = list[i];
      let j = i - 1;
      while (j >= 0 && list[j] > key) {
        list[j + 1] = list[j];
        j -= 1;
      }
      list[j + 1] = key;     
    }
  }

  /**
   * Performs the insertion sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  mergeSort= (list) => {
    if (list.length > 1) {
      const mid = Math.floor(list.length/2);
      const left = list.slice(0, mid);
      const right = list.slice(mid, list.length);

      this.mergeSort(left);
      this.mergeSort(right);
      this.merge(list, left, right);
    }
  }
  /**
   * Performs the insertion sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   * @param {Number} start 
   * @param {Number} end 
   */
  merge_Sort = (list, start, end) => {
    if (start < end) {
      const mid = Math.floor((start + end)/2);
      this.merge_Sort(list, start, mid);
      this.merge_Sort(list, mid + 1, end);
      this.merge_procedure(list, start, mid, end);
    }
  }

  /**
   * Merges the two sublists into the final sorted list
   * 
   * @param {Array} list 
   * @param {Array} left 
   * @param {Array} right 
   */
  merge = (list, left, right) => {
    let i = 0;
    let j = 0;

    while (i + j < list.length) {
      if (j == right.length || (i < left.length && left[i] < right[j])) {
        list[i + j] = left[i];
        i += 1;
      }
      else
      {
        list[i + j] = right[j];
        j += 1;
      }
    }
  }

  /**
   * Merges the two sublists into the final sorted list
   * 
   * @param {Array} list 
   * @param {Number} start 
   * @param {Number} mid 
   * @param {Number} end 
   */
  merge_procedure = (list, start, mid, end) => {
    let l = 0;
    let r = 0;
    let k = start;

    const left = new Array(mid - start + 1);
    const right = new Array(end - mid);

    for (let i = 0; i < left.length; i++) {
      left[i] = list[start + i];
    }

    for (let i = 0; i < right.length; i++) {
      right[i] = list[mid + i + 1];
    }

    while (l < left.length && r < right.length) {
      if (left[l] < right[r]) {
        list[k] = left[l];
        l+=1;
      }
      else
      {
        list[k] = right[r];
        r+=1;
      }
      k+=1;
    }

    while (l < left.length ) {
      list[k] = left[l];
      l+=1;
      k+=1;
    }

    while (r < right.length) {
      list[k] = right[r];
      r+=1;
      k+=1;
    }
  }

  /**
   * Performs the quick sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  quickSort = (list) => {
    this.quickSortProcedure(list, 0, list.length - 1);
  }

  /**
   * Performs the actual sort procedure
   * 
   * @param {Array} list 
   * @param {Number} start 
   * @param {Number} end 
   */
  quickSortProcedure = (list, start, end) => {
    if (start < end) {
      const point = this.partition(list, start, end);
      this.quickSortProcedure(list, start, point);
      this.quickSortProcedure(list, point + 1, end);
    }
  }

  /**
   * Performs hoare patition scheme
   * 
   * @param {Array} list 
   * @param {Number} start 
   * @param {Number} end 
   * @returns 
   */
  partition = (list, start, end) => {
    const pivot = this.median(list, start, end);
    while (true) {
      while (list[start] < list[pivot]) {
        start += 1;
      }
      while (list[end] > list[pivot]) {
        end -= 1;
      }
      if (start >= end) {
        return end;
      }
      this.swap(list, start, end);
      start += 1;
      end -= 1;
    }
  }

  /**
   * Performs the count sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  countSort = (list) => {
    //maximum number within the list
    const max = Math.max.apply(null, list);
    //holds the sorted array
    const aux = new Array(list.length);
    //array to hold the counts -  initialized with zero values
    const count = Array.from(Array(max + 1), () => 0);

    //frequency of the elements in the array
    list.forEach(e => {
      count[e] += 1;
    });

    /*cumulative counts which will represent the actual position 
     of the elements in the sorted list
    */
    for (let i = 1; i < count.length; i++) {
      count[i] += count[i - 1];
    }

    //build the sorted array
    for (let i = list.length - 1; i>=0; i--) {
       aux[--count[list[i]]] = list[i];
    }

    //copy back the sorted list
    for (let i = 0; i < aux.length; i++) {
      list[i] = aux[i];      
    }
  }

  /**
   * Performs the radix sort sort on the provided list.
   * The default sort is ascending
   * 
   * @param {Array} list 
   */
  radixSort = (list) => {
    //maximum number within the list
    const max = Math.max.apply(null, list);
    const digits = this.getDigits(max);
    let pos = 1;

    for (let i = 0; i < digits; i++) {
      this.radixCountSort(list, pos);
      pos *= 10;   
    }
  }

  /**
   * performs count sort procedure which is consumed by the radix sort
   * 
   * @param {Array} list 
   * @param {Number} pos 
   */
  radixCountSort = (list, pos) => {
    //holds the sorted array
    const aux = new Array(list.length);
    //array to hold the counts -  initialized with zero values
    const count = Array.from(Array(10), () => 0);

    //frequency of the elements in the array
    list.forEach(e => {
      count[Math.floor((e/pos)%10)] += 1;
    });

    /*cumulative counts which will represent the actual position 
     of the elements in the sorted list
    */
    for (let i = 1; i < count.length; i++) {
      count[i] += count[i - 1];
    }

    //build the sorted array
    for (let i = list.length - 1; i>=0; i--) {
       aux[--count[Math.floor((list[i]/pos)%10)]] = list[i];
    }

    //copy back the sorted list
    for (let i = 0; i < aux.length; i++) {
      list[i] = aux[i];      
    }
  }


  heapSort = (list) => {
    //build the max-heap
    this.buildMaxHeap(list);
    //perform sort by deleting from the maxheap
    for (let i = list.length -1; i >=0; i--) {
      this.swap(list, 0, i);
      //ensure that the max heap property is maintained
      this.maxHeapify(list, 0, i - 1);      
    }
  }

  /**
   * builds the max heap
   * 
   * @param {Array} list 
   */
  buildMaxHeap = (list) => {
    let i = Math.floor(list.length/2);
    for (; i >= 0; i--) {
      this.maxHeapify(list, i, list.length - 1);
    }
  }

  /**
   * Maintains the max-heap property
   * 
   * @param {Array} list 
   * @param {Number} length 
   * @param {Number} i 
   */
  maxHeapify = (list, i, length) => {
    let largest = i;
    let l = i*2;
    let r = i*2 + 1;

    if (l <= length && list[l] > list[largest]) {
      largest = l;
    }

    if (r <= length && list[r] > list[largest]) {
      largest = r;
    }

    if(i != largest) {
      this.swap(list, i, largest);
      this.maxHeapify(list, largest, length);
    }
  }

  /**
   * Return the number of digits that makes up the max digit number
   * 
   * @param {Number} max 
   * @returns digits
   */
  getDigits = (max) => {
    let digits = 0;
    while (max != 0) {
      max  = Math.floor(max/10);
      digits += 1;
    }
    return digits;
  }

  /**
   * Returns the median of the three values
   * 
   * @param {Array} list 
   * @param {Number} start 
   * @param {Number} end 
   * @returns 
   */
  median = (list, start, end) => {
    const mid = Math.floor((start + end)/2);
    const x = list[mid] - list[start];
    const y = list[start] - list[end];
    const z = list[mid] - list[end];

    return (x*y > 0 ? start : x*z > 0 ? end : mid);
  }

  /**
   * Interchanges the values of the two param values
   * 
   * @param {Number} x 
   * @param {Number} y 
   */
  swap = (list, i, j) => {
    const temp = list[i];
    list[i] = list[j];
    list[j] = temp;
  }
}

module.exports = new Sort();