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

	int last = 0;
	//std::clock_t start = std::clock();
	std::ofstream file;
	file.open("sorted.txt");

	for (int i = 0; i < 500000; i++) {
		int current = heap.deleteMin();
		if (i % 10 == 0) {
			file << current << "\n";
		} else {
			file << current << "\t";
		}
	}

	file.close();

	//printf("Finished in %.0fms\n", (std::clock() - start)/ (double) (CLOCKS_PER_SEC / 1000));

	return 0;
}