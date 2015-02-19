#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <ctime>


#include "heap.cpp"

int main(int argc, char const *argv[])
{
	BinaryHeap heap;

	std::srand(std::time(0));
	// Test with 500,000 elements
	for (int i = 0; i < 500000; i++) {
		heap.insert(std::rand());
	}

	int last = 0;
	std::clock_t start = std::clock();
	for (int i = 0; i < 500000; i++) {
		int current = heap.deleteMin();
		if (current < last) {
			printf("Out of order!");
		}
	}

	printf("Finished in %.0fms\n", (std::clock() - start)/ (double) (CLOCKS_PER_SEC / 1000));

	return 0;
}