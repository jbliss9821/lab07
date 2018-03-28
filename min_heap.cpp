#include <iostream>
#include "min_heap.h"

min_heap()
{
	heap = new int[500];
	for (int i = 0; i < 500; i++)
	{
		heap[i] = -1;//means it is empty
	}
	size = 0;
}

~min_heap()
{
	delete[] heap;
}

void insert_start(int value)
{
	heap[size] = value;
	size++;
}

void build_heap()
{
	for (int i = ((size / 2) -1); i >= 0; i--)
	{
		heapify(i);
	}
}

void heapify(int index)
{
	//check for smallest child
	//if smallest child is less than the current, swap
	//if swap, check the child's children
	int smallest_child = 5*index + 1;
	for (int i = 1; i < 6; i++)
	{
		int child = 5*index + i;
		if (heap[child] > -1 && heap[child] < heap[smallest_child])//if the child is a valid value and is less than the current smallest child, it is the new smallest child
		{
			smallest_child = child;
		}		
	}
	if (heap[smallest_child] < heap[index])
	{
		//swap
		int temp = heap[index];//current value to swap down
		heap[index] = heap[smallest_child];//current index will now hold the smallest child value
		heap[smallest_child] = temp;//smallest child index will now hold the previous parent/current index value
		heapify(smallest_child);//recursive call to newly swapped down value to fix any issues that may come from swapping down
	}
	else
	{
		//don't swap
	}
}

void insert(int value)
{
	heap[size] = value;
	size++;
	heapify((size / 2) -1);//heapify from parent of the inserted value which is put at bottom of the heap
}

bool delete_min()
{
	heap[0] = heap[size-1];
	heap[size-1] = -1;
	size--;
	heapify(0);//heapify from the top
}

bool delete_max()
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

void find_min()
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

void find_max()
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

void level_order()
{
	for (int i = 0; i < 4; i++)
	{
		
	}
}

bool is_leaf(int index)
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