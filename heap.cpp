#define INITIAL_HEAP_SIZE 10

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "heap.h"

/*
A BinaryHeap which can take any element except for MIN_INTEGER
*/

// Helper methods to get the indexes of parents and children
int getLeftChildIndex(int index) { return index * 2; }

int getRightChildIndex(int index) { return index * 2 + 1; }

int getParentIndex(int index) { return index / 2; }

BinaryHeap::BinaryHeap() {
	heap = new int[INITIAL_HEAP_SIZE]; // Initialize the heap with the given size
	heapSize = INITIAL_HEAP_SIZE; // The size of the heap
	current = 1; // Our current index

	// Initialize all our elements to be null
	for (int i = 0; i < heapSize; i++) {
		heap[i] = INT_MIN;
	}
}

// Insert an element into the heap, and resize the heap array if necessary
bool BinaryHeap::insert(int element) {
	// Resize the heap if we need to
	if (current + 1 == heapSize) {
		if (heapSize * 2 > INT_MAX) {
			return false;
		} else {
			resize();
		}
	}

	// Add the element at the end of the tree
	heap[current] = element;

	// Percolate it up the tree until it's at the correct position
	percolateUp(current);

	current++;

	return true;
}

// Resizes the heap array to 2 * heapSize
void BinaryHeap::resize() {
	int * oldArr = heap;
	int * newArr = new int[heapSize * 2];

	for (int i = 0; i < heapSize; i++) {
		newArr[i] = oldArr[i];
	}

	heapSize *= 2;
	heap = newArr;
}

// Retrieves the current size of our heap array
int BinaryHeap::getHeapSize() {
	return heapSize;
}

// Retrieves the ptr to the heap
int * BinaryHeap::getHeap() {
	return heap;
}

// Returns the size of the heap
int BinaryHeap::getSize() {
	return current - 1;
}

// Deletes the minimum element from the heap and returns it
int BinaryHeap::deleteMin() {
	if (getSize() == 0) {
		return INT_MIN;
	}

	int min = heap[1];
	heap[1] = heap[current--];
	heap[current] = INT_MIN;
	percolateDown(1);
	return min;
}

// Percolate an element down to the bottom of the tree, switching with the smallest child it is greater than
void BinaryHeap::percolateDown(int index) {
	int parent = heap[index];

	int leftChildIndex = getLeftChildIndex(index);
	int rightChildIndex = getRightChildIndex(index);

	// Set left/right children to INT_MIN if their index is out of bounds
	int leftChild = leftChildIndex < current ? heap[leftChildIndex] : INT_MIN;
	int rightChild = rightChildIndex < current ? heap[rightChildIndex] : INT_MIN;
	
	if (parent > leftChild && leftChild < rightChild && leftChild != INT_MIN) {
		heap[leftChildIndex] = parent;
		heap[index] = leftChild;
		percolateDown(leftChildIndex);
		return;
	}

	if (parent > rightChild && rightChild <= leftChild && rightChild != INT_MIN) {
		heap[rightChildIndex] = parent;
		heap[index] = rightChild;
		percolateDown(rightChildIndex);
		return;
	}

}

// Percolate an element up the tree until it is in the proper location, switching only with elements that are larger than it
void BinaryHeap::percolateUp(int index) {
	int parentIndex = getParentIndex(index);

	// We have percolated all the way to the top of the tree
	if (parentIndex <= 0) {
		return;
	}

	int parent = heap[parentIndex];
	int current = heap[index];
	// Swap elements if the parent is greater than the current element 
	if (parent > current) {
		heap[parentIndex] = current;
		heap[index] = parent;

		percolateUp(parentIndex);
	}
}

// Sorts the array which is passed in by inserting it into the heap and then removing elements and replacing them in the array
void BinaryHeap::sort(int * array, int arraySize) {
	
}