/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : MaxHeap implementation Part 2A)
*/
#include "MaxHeap.h"
#include <iostream>
using namespace::std;


MaxHeap::MaxHeap()
{
    numOfItems = 0;
    size = 2;
    items = new int[size];
}

MaxHeap::~MaxHeap()
{
    //dtor
}

int MaxHeap :: getSize()
{
    return numOfItems;
}

int MaxHeap :: getMax()
{
    return items[0];
}

int MaxHeap :: removeMax()
{
    if ( numOfItems == 0 )
        return -1;
    else
    {
        int root = items[0];
        items[0] = items[numOfItems - 1];
        items[numOfItems - 1] = -1;
        numOfItems--;
        heapRebuild(0);
    }
}

void MinHeap :: heapRebuild( int root )
{
    int child = 2 * root + 1;
    if ( child < numOfItems )
    {
        int rightChild = child + 1;
        if ( (rightChild < numOfItems) && ( items[rightChild] ) > items[child] )
            child = rightChild;
        if ( items[root] < items[child] )
        {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            heapRebuild(child);
        }
    }
		
}

void MaxHeap :: insert( int value)
{
    if ( numOfItems == size )
    {
        //Create a temporary array with double the size of old array
        int * temp = new int[size*2];
        //Copy each element into temporary array
        for ( int i = 0; i < size; i++ )
        {
            temp[i] = items[i];
        }
        //New tree is the temporary tree with double the size
        items = temp;
        //Private variable currSize has doubled
        size *= 2;
    }
    //Place the new item at the end of the heap
    items[numOfItems] = value;
    // Trickle new item up to its proper position
	int place = numOfItems;
	int parent = (place - 1)/2;
	while ( (place >= 0) && (items[place] > items[parent] ) ) {
		int temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1)/2;
	}
 	++numOfItems;


}
