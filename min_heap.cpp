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
	int smallest_child = 5*index + 1;
	for (int i = 1; i < 6; i++)
	{
		int child = 5*index + i;
		if (heap[child] != -1)
		{
			std::cout << "index: " << child << "\n";
			std::cout << "value: " << heap[child] << "\n\n";
		}
		//if (heap[child] > -1 && heap[child] < heap[smallest_child])//if the child is a valid value and is less than the current smallest child, it is the new smallest child
		//{
			//smallest_child = child;
		//}
	}
	//if (heap[smallest_child] < heap[index])
	//{
		//swap
		//int temp = heap[index];//current value to swap down
		//heap[index] = heap[smallest_child];//current index will now hold the smallest child value
		//heap[smallest_child] = temp;//smallest child index will now hold the previous parent/current index value
		//heapify(smallest_child);//recursive call to newly swapped down value to fix any issues that may come from swapping down
	//}
	//else
	//{
		//don't swap
	//}
}

void min_heap::insert(int value)
{
	heap[size] = value;
	size++;
	heapify((size / 2) -1);//heapify from parent of the inserted value which is put at bottom of the heap
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
	for (int i = 1; i < 6; i++)
	{
		int child = 5*index + i;
		if (heap[child] == -1)
		{
			return (false);
		}
	}
	return (true);
}





































//
