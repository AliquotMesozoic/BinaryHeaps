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
	heap.insert(8);

	int * hArr = heap.getHeap();

	printf("[");
	for (int i = 0; i < heap.getHeapSize(); i++) {
		if (i != heap.getHeapSize() - 1) {
			printf("%d, ", hArr[i]);
		} else {
			printf("%d]\n", hArr[i]);
		}
	}	

	return 0;
}