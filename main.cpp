/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : Main method Part 2F)
*/
#include "MaxHeap.h"
#include "MinHeap.h"
#include "AVLTree.h"
#include "analysis.h"
#include <iostream>
#include "QuickMedian.h"
using namespace::std;
int main()
{
    MaxHeap maxheap;
    maxheap.insert(40);
    maxheap.insert(50);
    maxheap.insert(45);
    maxheap.insert(30);
    maxheap.insert(60);
    maxheap.insert(55);
    maxheap.insert(20);
    maxheap.insert(35);
    maxheap.insert(10);
    maxheap.insert(25);
    cout << " ---------------------------------- " << endl;
    cout << " MAX HEAP: " << endl;
    cout << " Max:" << maxheap.getMax() << endl;
    cout << " Size:" << maxheap.getSize() << endl;
    cout << " ---------------------------------- " << endl;

    MinHeap minheap;
    minheap.insert(40);
    minheap.insert(50);
    minheap.insert(45);
    minheap.insert(30);
    minheap.insert(60);
    minheap.insert(55);
    minheap.insert(20);
    minheap.insert(35);
    minheap.insert(10);
    minheap.insert(25);


    cout << " ---------------------------------- " << endl;
    cout << " MIN HEAP: " << endl;
    cout << " Min:" << minheap.getMin() << endl;
    cout << " Size:" << minheap.getSize() << endl;
    cout << " ---------------------------------- " << endl;


    QuickMedian qheap;

    qheap.insert(10);
    qheap.insert(40);
    qheap.insert(30);
    qheap.insert(50);
    qheap.insert(70);
    qheap.insert(60);
    qheap.insert(20);
    qheap.insert(90);
    qheap.insert(100);
    qheap.insert(110);
    qheap.insert(0);
    qheap.insert(25);
    qheap.insert(123);
    qheap.insert(11);
    qheap.insert(200);

    cout << "Median is": qheap.getMedian() << endl;

    heightAnalysis();

    return -1;
}
