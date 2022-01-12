const sort = require('./sort');
list = [...Array(99)].map(e=>~~(Math.random()*999))

console.log(list)

//BUBBLE SORT
// sort.bubbleSort(list);

//SELECTION SORT
// sort.selectionSort(list);

//INSERTION SORT
// sort.insertionSort(list);

//MERGE SORT
// sort.mergeSort(list);
// sort.merge_Sort(list,0,list.length - 1)

//QUICK SORT
// sort.quickSort(list);

//COUNT SORT
// sort.countSort(list);

//RADIX COUNT
// sort.radixSort(list);

//HEAP SORT
sort.heapSort(list);

console.log(list)