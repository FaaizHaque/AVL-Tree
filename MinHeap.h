/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : MinHeap header file Part 2B)
*/
#ifndef MINHEAP_H
#define MINHEAP_H


class MinHeap
{
    public:
        MinHeap();
        virtual ~MinHeap();
        void insert(int val);
        int getMin();
        int removeMin();
        int getSize();
        void heapRebuild(int root);

    protected:

    private:
        int size;
        int numOfItems;
        int *items;
};

#endif // MINHEAP_H
