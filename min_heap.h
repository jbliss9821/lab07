#ifndef MIN_HEAP
#define MIN_HEAP

class min_heap
{
	public:
		min_heap();
		~min_heap();
		void insert_start(int value);//inserts into the array without care for order then use build to build the heap
		void build_heap();
		void heapify(int index);
		void insert(int value);
		bool delete_min();
		bool delete_max();
		void find_min();//print min
		void find_max();//print max
		void level_order();//print level order traversal
		bool is_leaf(int index);
	
	private:
		int size;
		int* heap;
};

#endif