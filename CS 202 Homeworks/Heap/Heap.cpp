/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Implementation file for heap.
* Templated class, to be able to use both for computer
* and log.
*/
#include "Heap.h"

template<typename T>
// Default constructor 
Heap<T>::Heap() : size(0) {

}

template <typename T>
void Heap<T>::setSize(int inputSize)
{
	items = new T[inputSize];
	size = 0;
}

template <typename T>
bool Heap<T>::heapIsEmpty() const
{
    return (size == 0);
}

template <typename T>
void Heap<T>::heapInsert(const T newItem)
{
	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[place]->getKey() > items[parent]->getKey()) ) {
		T temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++size;
}

template <typename T>
void Heap<T>::heapDelete()
{
	items[0] = items[--size];
	heapRebuild(0);
}

template <typename T>
T Heap<T>::top()
{
    return items[0];
}

template <typename T>
Heap<T>::~Heap()
{
    delete[] items;
}

template <typename T>
void Heap<T>::heapRebuild(int root)
{
    int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size) &&
		     (items[rightChild]->getKey() >items[child]->getKey() || (items[rightChild]->getKey() == items[child]->getKey()
			 && items[rightChild]->id < items[child]->id)) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root]->getKey() < items[child]->getKey() ) {
			T temp = items[root];
			items[root] = items[child];
			items[child] = temp;
		}
		if(items[root]->getKey() == items[child]->getKey() && items[child]->id < items[root]->id){
			T temp = items[root];
			items[root] = items[child];
			items[child] = temp;
		}
			// transform the new subtree into a heap
			heapRebuild(child);
    }
}
template class Heap<Computer*>;
template class Heap<Log*>;