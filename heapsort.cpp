#include <stdlib.h>
#include <stdio.h>

#include "heap.cpp"

int main(int argc, char const *argv[])
{
	BinaryHeap heap;

	int arr[5] = {5, 2, 4, 1, 3};

	heap.sort(arr);

	printf("[");
	for (int i = 0; i < 5; i++) {
		if (i == 4) {
			printf("%d]\n", arr[i]);
		} else {
			printf("%d, ", arr[i]);
		}
	}

	return 0;
}