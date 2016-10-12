/***************************************************
	DO NOT MODIFY THIS FILE
	Data Structure & Algorithm Assignment 3
	Heap.cpp
	Purpose: Implementation for the Heap class

	@author Kien Huynh
	@version 1.1 02-10-2016
***************************************************/

#include "Heap.h"
void Heap::swap(int a, int b) {
	int tempVal = heapPtr[a];
	heapPtr[a] = heapPtr[b];
	heapPtr[b] = tempVal;
}

void Heap::ReHeapUp(int position) {
	if (position > 0) {
		int parent = (position - 1) / 2;
		if (heapPtr[position] > heapPtr[parent]) {
			swap(position, parent);
			ReHeapUp(parent);
		}
	}
}

void Heap::ReHeapDown(int position) {
	int leftChild = position * 2 + 1;
	int rightChild = position * 2 + 2;
	int largeChild = 0;
	if (leftChild <= last && heapPtr[rightChild] > heapPtr[leftChild]) {
		largeChild = rightChild;
	}
	else {
		largeChild = leftChild;
	}
	if (heapPtr[largeChild] > heapPtr[position]) {
		swap(largeChild, position);
		ReHeapDown(largeChild);
	}
}

bool Heap::ArrToHeap(int* arr, int length){
	size = 0;
	last = -1;
	heapPtr = new int[length];
	for (int i = 0; i < length; i++) {
		heapPtr[i] = arr[i];
	}
	for (int i = 0; i < length; i++) {
		if (i == HEAP_MAX) {
			return false;
		}
		ReHeapUp(i);
		size++;
		last++;
	}
	return true;
}

Heap::Heap() {
	heapPtr = NULL;
	last = 0;
	maxSize = HEAP_MAX;
	size = 0;
}

Heap::Heap(int* arr, int length) {
	ArrToHeap(arr, length);
}

int Heap::operator [](const int i){
	if (i < size && i >= 0) {
		return heapPtr[i];
	}
	else {
		cout << "Heap index out of bound, returning -1.";
		return -1;
	}
};

bool Heap::IsEmpty() {
	if (heapPtr == NULL) {
		return true;
	}
	return false;
}

bool Heap::IsFull() {
	if (size == HEAP_MAX) {
		return true;
	}
	return false;
}

void Heap::PrintHeapLinear() {
	for (int i = 0; i < size; i++) {
		cout << heapPtr[0] << " ";
	}
	cout << endl;
}

void Heap::PrintHeapTreeRe(int position, int indent) {
	if (position * 2 + 2 < size) {
		PrintHeapTreeRe(position * 2 + 2, indent+1);
	}
	for (int i = 0; i < indent; i++) {
		cout << "\t";
	}
	cout << heapPtr[position] << endl;
	if (position * 2 + 1 < size) {
		PrintHeapTreeRe(position * 2 + 1, indent + 1);
	}
}

void Heap::PrintHeapTree() {
	PrintHeapTreeRe(0, 0);
}

bool Heap::InsertHeap(int data) {
	if (IsFull()) {
		return false;
	}
	last++;
	size++;
	heapPtr[last] = data;
	ReHeapUp(last);
	return true;
}