/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : QuickMedian header file Part 2C)
*/
#ifndef QUICKMEDIAN_H
#define QUICKMEDIAN_H
#include "MaxHeap.h"
#include "MinHeap.h"


class QuickMedian
{
    public:
        QuickMedian();
        virtual ~QuickMedian();
        void insert(int val);
        double getMedian();
    protected:

    private:
        MinHeap minHeap;
        MaxHeap maxHeap;
        int median;

};

#endif // QUICKMEDIAN_H
