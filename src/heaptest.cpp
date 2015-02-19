#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>


#include "heap.cpp"

int main(int argc, char const *argv[])
{
	BinaryHeap heap;

	std::srand(std::time(0));
	// Test with 500,000 elements
	for (int i = 0; i < 500000; i++) {
		heap.insert(std::rand());
	}

	std::clock_t start = std::clock();

	for (int i = 0; i < 500000; i++) {
		heap.deleteMin();
	}

	printf("Finished sort of 500,000 random elements in %.0fms\n", (std::clock() - start)/ (double) (CLOCKS_PER_SEC / 1000));

	for (int i = 500000; i > 0; i--) {
		heap.insert(i);
	}

	start = std::clock();
	for (int i = 0; i < 500000; i++) {
		heap.deleteMin();
	}

	printf("Finished sort of 500,000 backwards elements in %.0fms\n", (std::clock() - start)/ (double) (CLOCKS_PER_SEC / 1000));

	return 0;
}