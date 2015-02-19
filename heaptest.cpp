#include <stdlib.h>
#include <stdio.h>

#include "heap.cpp"

int main(int argc, char const *argv[])
{
	BinaryHeap heap;

	heap.insert(3);
	heap.insert(5);
	heap.insert(2);
	heap.insert(1);
	heap.insert(9);

	for (int i = 0; i < heap.getSize() + 1; i++) {
		printf("%d, ", heap.getHeap()[i]);
	}

	// return 0;
}