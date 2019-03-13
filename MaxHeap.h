/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : MaxHeap header file Part 2A)
*/

#ifndef MAXHEAP_H
#define MAXHEAP_H


class MaxHeap
{
    public:
        MaxHeap();
        virtual ~MaxHeap();
        void insert(int val);
        int getMax();
        int removeMax();
        int getSize();
        void heapRebuild(int root);


    protected:

    private:
        int size;
        int numOfItems;
        int *items;
};

#endif // MAXHEAP_H
