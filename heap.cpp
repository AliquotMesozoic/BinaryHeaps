#define INITIAL_HEAP_SIZE 10

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
	this->heap = new int[INITIAL_HEAP_SIZE]; // The ptr to the array that represents our binary heap
	this->heapSize = INITIAL_HEAP_SIZE; // The size of the heap
	this->current = 1; // Our current index

	// Initialize all our elements to be null
	for (int i = 0; i < this->heapSize; i++) {
		this->heap[i] = INT_MIN;
	}
}

// Insert an element into the heap, and resize the heap array if necessary
bool BinaryHeap::insert(int element) {
	// Resize the heap if we are at 
	if (this->current + 1 == this->heapSize) {
		if (this->heapSize * 2 > INT_MAX) {
			return false;
		}
	}

	// Add the element at the end of the tree
	this->heap[this->current++] = element;

	// Percolate it up the tree until it's at the correct position
	this->percolateUp(this->current - 1);
}

// Resizes the heap array to 2 * heapSize
void BinaryHeap::resize() {
	int * oldArr = this->heap;
	int * newArr = new int[this->heapSize * 2];

	for (int i = 0; i < this->heapSize; i++) {
		newArr[i] = oldArr[i];
	}

	this->heapSize *= 2;
	this->heap = newArr;
}

// Retrieves the current size of our heap array
int BinaryHeap::getHeapSize() {
	return this->heapSize;
}

// Retrieves the ptr to the heap
int * BinaryHeap::getHeap() {
	return this->heap;
}

// Returns the size of the heap
int BinaryHeap::getSize() {
	return this->current - 1;
}

// Percolate an element down to the bottom of the tree, switching with the smallest child
void BinaryHeap::percolateDown(int index) {

}

// Percolate an element up the tree until it is in the proper location, switching only with elements that are larger than it
void BinaryHeap::percolateUp(int index) {
	int parentIndex = getParentIndex(index);
	// We have percolated all the way to the top of the tree
	if (parentIndex <= 0) {
		return;
	}

	int parent = this->heap[parentIndex];
	int current = this->heap[index];
	// Swap elements if the parent is greater than the current element 
	if (exists(index) && parent > current) {
		this->heap[parentIndex] = current;
		this->heap[index] = parent;

		this->percolateUp(parentIndex);
	}
}

// Sorts the array which is passed in by inserting it into the heap and then removing elements and replacing them in the array
void BinaryHeap::sort(int * array, int arraySize) {
	
}

// Returns true if the element at the specified index exists
bool BinaryHeap::exists(int index) {
	return (index > 0 && index < this->heapSize && this->heap[index] != INT_MIN);
}