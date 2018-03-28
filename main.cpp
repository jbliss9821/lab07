#include <iostream>
#include <fstream>
#include "min_heap.h"

int main()
{
  std::ifstream infile;
  infile.open("data.txt");
  min_heap heap;
  int temp;

  while(infile >> temp)
  {
    heap.insert_start(temp);
  }
  heap.level_order();
  heap.find_min();
  heap.find_max();
  heap.build_heap();

  return 0;
}
