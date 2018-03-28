//author: Johnathon Bliss
//date: 04/30/17
//lab: 9
//description: Heap implementation templated to type T.  Checks for size, is_empty, can add and then uphead
//	can remove and then downheap, and can print out priority for testing purposes.  Peek top for
//	printing truck loading and then destructor gets rid of packages and the heap
#include <iostream>
#include <string>
#include <stdexcept>
#include "package.h"

template <typename T>
heap<T>::heap()
{
	array = new T[1000];
	size = 0;
}

template <typename T>
void heap<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		T temp = array[i];
		std::cout << temp.get_priority() << std::endl;
	}
}

template <typename T>
bool heap< T>::is_empty() const
{
	if(size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

template <typename T>
int heap<T>::get_size() const
{
	return(size);
}

template <typename T>
void heap< T>::add(T value)
{
	array[size] = value;
	size++;
	int index = size - 1;
	upheap(value, index);
}

template <typename T>
void heap< T>::upheap(T value, int index)
{
	if (index != 0)
	{
		T temp_child = array[index];
		T temp_parent = array[(index-1) /2];

		std::string t_child = temp_child->get_contents();
		std::string t_parent = temp_parent->get_contents();

		if (temp_child->get_priority_int() < temp_parent->get_priority_int())
		//if (array[index] < array[(index - 1) / 2])
		{
			array[index] = array[(index - 1) / 2];
			array[(index - 1) / 2] = value;
			upheap(value, ((index - 1) / 2));
		}
		if (temp_child->get_priority_int() == temp_parent->get_priority_int())
		{
			if (t_child[0] < t_parent[0])
			{
				array[index] = array[(index - 1) / 2];
				array[(index - 1) / 2] = value;
				upheap(value, ((index - 1) / 2));
			}
		}
	}
}

template <typename T>
void heap< T>::remove() throw (std::runtime_error)
{
	if(is_empty())
	{
		throw std::runtime_error("Can't remove on an empty heap");
	}
	else
	{
		T temp = array[size-1];
		array[0] = temp;
		array[size-1] = 0;
		size--;
		downheap(array[0], 0);
	}
}

template <typename T>
void heap< T>::downheap(T value, int index)
{
	int l_child = (2 * index) + 1;
	int r_child = (2 * index) + 2;
	int down_child;

	T temp_parent = array[index];
	T temp_left = array[l_child];
	T temp_right = array[r_child];

	if (index < size)//if not the last value
	{
		if (l_child <= (size-1) && temp_parent->get_priority_int() > temp_left->get_priority_int())//if left child index is within the size and the value is greater than that value
		{
			if (r_child <= (size-1))//if right child index is within the size
			{
				if(temp_left->get_priority_int() < temp_right->get_priority_int())//if the left child is less than the right child, swap with left child
				{
					down_child = l_child;
				}
				else//else swap with right child
				{
					down_child = r_child;
				}
			}
			else//else if there is no right child, swap with left child
			{
				down_child = l_child;
			}
		}
		else if (r_child <= (size-1) && temp_parent->get_priority_int() > temp_right->get_priority_int())//if left child is greater than value look at right child and check if right child is less than the value and exists
		{
			down_child = r_child;
		}
		else
		{
			return;
		}

		array[index] = array[down_child];
		array[down_child] = value;
		downheap(value, down_child);
	}
}

template <typename T>
T heap< T>::peek_top() const throw(std::runtime_error)
{
	if (is_empty())
	{
		throw std::runtime_error("Heap is empty");
	}
	else
	{
		return(array[0]);
	}
}

template <typename T>
heap<T>::~heap()
{
	for (int i = 0; i < size; i++)
	{
		delete array[i];
	}
	delete[] array;
}


















