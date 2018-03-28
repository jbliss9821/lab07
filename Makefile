prog: main.o min_heap.o
	g++ -std=c++11 -g -Wall main.o min_heap.o -o prog

main.o: main.cpp min_heap.h
	g++ -std=c++11 -g -Wall -c main.cpp

min_heap.o: min_heap.h min_heap.cpp
	g++ -std=c++11 -g -Wall -c min_heap.cpp

clean:
	rm *.o prog
