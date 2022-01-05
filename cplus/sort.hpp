#pragma once
#include <ctime>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::max_element;

class Sort
{
private:
  void swap(vector<int>&, int, int) const;
  void merge(vector<int>&, vector<int>&, vector<int>&) const;
  void _mergesort_procedure_(vector<int>&, int, int) const;
  void _merge_(vector<int>&, int, int, int) const;
  void quicksort_procedure(vector<int>&, int, int) const;
  void radix_countsort(vector<int> &, int, int) const;
  void buildmaxheap(vector<int> &, int) const;
  void maxheapify(vector<int> &, int, int) const;
  int partition(vector<int>&, int, int) const;
  int median_of_three(vector<int>&, int, int) const;
  int getdigits(int) const;
public:
  Sort();
  ~Sort();
  void bubblesort(vector<int>&) const;
  void selectionsort(vector<int>&) const;
  void insertionsort(vector<int>&) const;
  void recursive_insertionsort(vector<int>&, int) const;
  void mergesort(vector<int>&) const;
  void _mergesort_(vector<int>&) const;
  void quicksort(vector<int> &) const;
  void countsort(vector<int> &) const;
  void radixsort(vector<int>&) const;
  void heapsort(vector<int> &) const;
};
