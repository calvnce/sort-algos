#include <random>
#include "sort.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::random_device;
using std::mt19937_64;
using std::uniform_int_distribution;

int main(int argc, char const *argv[])
{
  //initialize the Sort Object Instance
  Sort s;

  //random value generation
  random_device rd;
  mt19937_64 engine(rd());
  uniform_int_distribution<int> dist(1, 5099);

  int len = 550;
  vector<int>v;
  v.reserve(len);

  for (int i = 0; i < len; i++)
  {
    v.push_back(dist(engine));
  }
  for (auto &i:v)
  {
    cout<<i<<" ";
  }
  cout<<endl<<endl;
  
  //BUBBLE SORT
  // s.bubblesort(v);

  //SELECTION SORT
  // s.selectionsort(v);

  //INSERION SORT
  // s.insertionsort(v);
  // s.recursive_insertionsort(v, len);


  //MERGE SORT
  // s.mergesort(v);
  // s._mergesort_(v);

  //QUICK SORT
  // s.quicksort(v);

  //COUNT SORT
  // s.countsort(v);

  //RADIX SORT
  // s.radixsort(v);

  //HEAP SORT
  s.heapsort(v);


  for (auto &i:v)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  
  
  return 0;
}
