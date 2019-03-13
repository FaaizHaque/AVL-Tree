/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : heightAnalysis implementation
*/
#include "analysis.h"
#include <iostream>
#include <cstdlib>
#include "AVLTree.h"
#include <iomanip>
using namespace::std;


void heightAnalysis()
{
    int sizes[20] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000,
                    12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000 };

    cout << "___________________________________________________________________________________________" << endl;
    cout << endl;
    cout << "Part e - Height Analysis Of AVL Trees " << endl;
    cout << " --------------------------------------------------------------------------------------------- " << endl;
    cout << setw(10) << " Array Size " << setw(10) << " Random " << setw(10) << " Ascending " << setw(10) << " Descending" << endl;
    cout << " ----------------------------------------------------------------------------------------------" << endl;

    for ( int j = 0; j < 20; j++ )
    {
        AVLTree treeRandom;
        AVLTree treeAsc;
        AVLTree treeDsc;
        for ( int i = 0; i < sizes[j]; i++ )
        {
            int temp = rand()%sizes[j];
            treeRandom.insert( temp );
        }

        for ( int i = 0; i < sizes[j]; i++ )
        {
            treeAsc.insert( i );
        }

        for ( int i = sizes[j]; i > 0; i-- )
        {
            treeDsc.insert(i);
        }

        cout << setw(10) << sizes[j] << setw(10) << treeRandom.getHeight() << setw(10) << treeAsc.getHeight()
             << setw(10) << treeDsc.getHeight() << endl;
    }
    cout << endl;
    cout << "___________________________________________________________________________________________" << endl;
}

