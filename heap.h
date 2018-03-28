//author: Johnathon Bliss
//date: 04/30/17
//lab: 9
//description: Head file for heap implementation templated to type T.  Checks for size, is_empty, can add and then uphead
//	can remove and then downheap, and can print out priority for testing purposes.  Peek top for
//	printing truck loading and then destructor gets rid of packages and the heap
#ifndef HEAP_H
#define HEAP_H

#include "heap_interface.h"
#include <stdexcept>

template <typename T>
class heap : public heap_interface<T>
{
    public:
	    heap();
		void add(T value);
		void print();
		bool is_empty() const;
		int get_size() const;
		void upheap(T value, int index);
		void remove() throw (std::runtime_error);
		void downheap(T value, int index);
		T peek_top() const throw(std::runtime_error);
		~heap();

    private:
		T* array;
		int size;
};

#include "heap.cpp"

#endif
