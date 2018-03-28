#include <iostream>
#include "min_heap.h"

min_heap::min_heap()
{
	heap = new int[500];
	for (int i = 0; i < 500; i++)
	{
		heap[i] = -1;//means it is empty
	}
	size = 0;
}

min_heap::~min_heap()
{
	delete[] heap;
}

void min_heap::insert_start(int value)
{
	heap[size] = value;
	size++;
}

void min_heap::build_heap()
{
	for (int i = (size / 5) - 1; i >= 0; i--)
	{
		std::cout << i << std::endl;
		heapify(i);
	}
}

void min_heap::heapify(int index)
{
	//check for smallest child
	//if smallest child is less than the current, swap
	//if swap, check the child's children
	std::cout << "heapify index is: " << index << "\n";
	if (index < 0 || index > 500)//check that the index is w/in the bounds
	{
		std::cout << "index out of bound\n";
		return;
	}
	else if (heap[index] == -1)//if the value is empty, go back up
	{
		std::cout << "index: " << index << " has no value.\n";
		return;
	}
	else if (is_leaf(index))//if the index is a leaft, go back up
	{
		std::cout << "index is leaf\n";
		return;
	}
	else//if w/in bounds, index isn't empty, and index isn't a leaf then we can check for values
	{
		int smallest_child_index = 5*index +1;
		std::cout << "smallest index is: " << smallest_child_index << "\n";
		for (int i = 1; i < 6; i++)
		{
			int current_child_index = 5*index + i;
			std::cout << "current index is: " << smallest_child_index << "\n";
			if (heap[current_child_index] > -1 && heap[current_child_index] < heap[smallest_child_index])
			{
				//if current index isn't empty and the current value < smallest value so far, update smallest value
				std::cout << "changing smallest value from: " << heap[smallest_child_index] << " to " << heap[current_child_index] << "\n";
				smallest_child_index = current_child_index;
			}
		}
		if (heap[smallest_child_index] < heap[index])
		{
			//if the the smallest child value is less than then current value, swap the values around
			std::cout << "\nchanging parent " << heap[index] << " to " << heap[smallest_child_index] << "\n";
			int temp_parent = heap[index];
			heap[index] = heap[smallest_child_index];
			heap[smallest_child_index] = temp_parent;
			heapify(smallest_child_index);//heapify down from swapped out value
		}
	}
}

void min_heap::insert(int value)
{
	heap[size] = value;
	size++;
	heapify((size / 5) -1);//heapify from parent of the inserted value which is put at bottom of the heap
}

bool min_heap::delete_min()
{
	if (size == 0)
	{
		return (false);
	}
	heap[0] = heap[size-1];
	heap[size-1] = -1;
	size--;
	heapify(0);//heapify from the top
	return(true);
}

bool min_heap::delete_max()
{
	if (size == 0)
	{
		return (false);
	}
	if (size == 1)
	{
		heap[0] = -1;
		size--;
		return(true);
	}
	int max = heap[0];
	int max_index = 0;
	for (int i = 0; i < size; i++)
	{
		if (heap[i] > max)
		{
			max_index = i;
			max = heap[i];
		}
	}
	heap[max_index] = -1;
	size--;
	if (max_index != size)
	{
		//need to shift values
	}
	return(true);
}

void min_heap::find_min()
{
	if (size > 0)
	{
		std::cout << "Min value is: " << heap[0] << "\n";
	}
	else
	{
		std::cout << "Empty heap, no min value.\n";
	}

}

void min_heap::find_max()
{
	if (size > 0)
	{
		int max = heap[0];
		for (int i = 0; i < size; i++)
		{
			if (heap[i] > max)
			{
				max = heap[i];
			}
		}
		std::cout << "Max value is: " << max << "\n";
	}
	else
	{
		std::cout << "Empty heap, no max value.\n";
	}
}

void min_heap::level_order()
{
	for (int i = 0; i < 500; i++)
	{
		if (heap[i] != -1)
		{
			std::cout << heap[i] << std::endl;
		}
	}
}

bool min_heap::is_leaf(int index)
{
	//std::cout << "index of is leaf is: " << index << "\n";
	for (int i = 1; i < 6; i++)
	{
		int child = 5*index + i;
		//std::cout << "index of is leaf child is: " << child << "\n";
		//std::cout << "value of is leaf child is: " << heap[child] << "\n";
		if (heap[child] == -1)
		{
			return (true);
		}
	}
	return (false);
}





































//
