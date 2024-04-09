/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Header file for heap.
* Templated class, to be able to use both for computer
* and log.
*/
#ifndef HEAP_H
#define HEAP_H
#include "Log.h"
#include "Computer.h"
template<typename T>
class Heap {
public:
	Heap();				// default constructor
	// copy constructor and destructor are supplied by the compiler

	void setSize(int size);
	bool heapIsEmpty() const;
	void heapInsert(const T newItem);
	void heapDelete();
	T top();
    ~Heap();
	T* items;	                // array of heap items

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at 
					        		// index root into a heap
private:
	int size;            	// number of heap items
};
#endif