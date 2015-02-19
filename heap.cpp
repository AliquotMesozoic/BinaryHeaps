#define INITIAL_HEAP_SIZE 10

#include <limits.h>
#include "heap.h"

/*
A BinaryHeap which can take any element except for MIN_INTEGER
*/

BinaryHeap::BinaryHeap() {
	this->heap = new int[INITIAL_HEAP_SIZE]; // The ptr to the array that represents our binary heap
	this->heapSize = INITIAL_HEAP_SIZE; // The size of the heap
	this->current = 1; // Our current index

	// Initialize all our elements to be null
	for (int i = 1; i < this->heapSize; i++) {
		this->heap[i] = INT_MIN;
	}
}

// Insert an element into the heap, and resize the heap array if necessary
void BinaryHeap::insert(int element) {

}

// Resizes the heap array to 2 * heapSize
void BinaryHeap::resize() {

}

// Retrieves the current size of our heap array
int BinaryHeap::getHeapSize() {
	return this->heapSize;
}

// Retrieves the ptr to the heap
int * BinaryHeap::getHeap() {
	return this->heap;
}

// Retrieves the element at the specified index
int BinaryHeap::getElement(int index) {
	return this->heap[index];
}

// Set the element at the specified index to the given value: primarily for internal use
void BinaryHeap::setElement(int index, int value) {

}

// Percolate an element down to the bottom of the tree, switching with the smallest child
void BinaryHeap::percolateDown(int index) {

}

// Percolate an element up the tree until it is in the proper location, switching only with elements that are larger than it
void BinaryHeap::percolateUp(int index) {

}

// Sorts the array which is passed in by inserting it into the heap and then removing elements and replacing them in the array
void BinaryHeap::sort(int * array) {

}




// Helper methods to get the indexes of parents and children
int getLeftChildIndex(int index) { return index * 2; }

int getRightChildIndex(int index) { return index * 2 + 1; }

int getParentIndex(int index) { return index / 2; }