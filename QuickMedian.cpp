/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : QuickMedian Part 2C)
*/
#include "QuickMedian.h"
#include <iostream>
using namespace::std;


QuickMedian::QuickMedian()
{
    //ctor
}

QuickMedian::~QuickMedian()
{
    //dtor
}


void QuickMedian :: insert(int val)
{

    if ( val > maxHeap.getMax() || maxHeap.getSize() == 0 )
        maxHeap.insert(val);
    else
        minHeap.insert(val);

    if ( minHeap.getSize() - maxHeap.getSize() >=2 )
    {
        minHeap.insert( maxHeap.getMax() );
        maxHeap.removeMax();
    }
    else if ( maxHeap.getSize() - minHeap.getSize() >=2 )
    {
        maxHeap.insert( minHeap.getMin() );
        minHeap.removeMin();
    }
}

double QuickMedian :: getMedian()
{
    if (  (maxHeap.getSize() + minHeap.getSize() ) % 2 == 0 )
        return  ( maxHeap.getMax() + minHeap.getMin() ) / 2;
    else
    {
        if ( maxHeap.getSize() >= minHeap.getSize() )
            return maxHeap.getMax();
        else
            return minHeap.getMin();
    }
}
