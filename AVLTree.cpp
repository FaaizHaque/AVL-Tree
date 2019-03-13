/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : AVL TREE implementation
*/
#include "AVLTree.h"
#include <cstddef>
#include <cmath>
#include <iostream>
using namespace::std;
AVLTree::AVLTree()
{
    root = NULL;
    insertions = 0;
}

AVLTree::~AVLTree()
{
    //dtor
}


void AVLTree :: insert( int value )
{
    bool leftChild;
    insertions++;
    if ( root == NULL )
    {
        root = new Node();
        root->item = value;
    }
    else
    {
        Node * curr = root;
        Node * prev;
        while ( curr != NULL )
        {
            prev = curr;
            if ( value < curr->item )
            {
                curr = curr->left;
                leftChild = true;
            }
            else
            {
                curr = curr->right;
                leftChild = false;
            }
        }
        curr = new Node();
        curr->item = value;

        if ( leftChild )
            prev->left = curr;
        else
            prev->right = curr;

        Node * temp;
        if ( !isBalanced(root, temp ) )
        {
            if ( curr->item < temp->item  ) //LEFT SUBTREE INSERTION OCCURED
            {
                if ( leftChild ) //LEFT CHILD AND LEFT SUBTREE
                    singleRR(temp,prev,curr);
                else //RIGHT CHILD AND LEFT SUBTREE
                    doubleLRR(temp, prev, curr);

            }
            else if ( curr->item > temp->item ) //RIGHT SUBTREE INSERTION
            {
                if ( !leftChild ) //RIGHT CHILD AND RIGHT SUBTREE
                    singleLR(temp,prev,curr);
                else //LEFT CHILD AND RIGHT SUBTREE
                    doubleRLR(temp, prev, curr );
            }
        }
    }
}

void AVLTree :: doubleRLR( Node * first, Node * second, Node * third )
{
    Node * newThird = new Node();

    newThird->item = second->item;
    second->right = newThird;

    second->item = third->item;

    delete second->left;
    second->left = NULL;

    singleLR( first, second, newThird );
}

void AVLTree :: doubleLRR( Node * first, Node * second, Node * third )
{
    Node * newThird = new Node();

    newThird->item = second->item;
    second->left = newThird;

    second->item = third->item;

    delete second->right;
    second->right = NULL;

    singleRR( first, second, newThird );
}

void AVLTree :: singleRR( Node* first, Node *second, Node * third)
{
    Node * newFirst = new Node();
    first->right = newFirst;

    newFirst->item = first->item;
    first->item = second->item;
    second->item = third->item;

    delete second->left;
    second->left = NULL;
}

void AVLTree :: singleLR( Node * first, Node * second, Node * third )
{
     Node * newFirst = new Node();
     first->left = newFirst;

     newFirst->item = first->item;
     first->item = second->item;
     second->item = third->item;

     delete second->right;
     second->right = NULL;

}

bool AVLTree :: isBalanced( Node * curr, Node *&temp )
{
    int leftHeight;
    int rightHeight;

    if ( curr == NULL )
        return true;

    leftHeight = getHeight(curr->left);
    rightHeight = getHeight(curr->right);

    if ( abs( rightHeight - leftHeight ) <= 1 && isBalanced(curr->left,temp) && isBalanced(curr->right,temp) )
    {
        return true;
    }

    temp = curr;

    return false;
}

int AVLTree :: getHeight( Node * root )
{
    int leftHeight, rightHeight;
    if ( root == NULL )
        return 0;
    else
    {
        leftHeight = 1 + getHeight(root->left);
        rightHeight = 1 + getHeight(root->right);
        if ( leftHeight > rightHeight )
            return leftHeight;
        else
            return rightHeight;
    }

}

int AVLTree :: getHeight()
{
    if ( insertions == 0 )
        return 0;
    else if ( insertions == 1)
        return 1;
    else if ( insertions < 4 && insertions >= 2)
        return 2;
    else if ( insertions < 8 && insertions >= 4)
        return 3;
    else if ( insertions < 16 && insertions >= 8)
        return 4;
    else if ( insertions < 32 && insertions >= 16)
        return 5;
    else if ( insertions < 64 && insertions >= 32)
        return 6;
    else if ( insertions < 128 && insertions >= 64)
        return 7;
    else if ( insertions < 256 && insertions >= 128)
        return 8;
    else if ( insertions < 512 && insertions >= 256)
        return 9;
    else if ( insertions < 1024 && insertions >= 256)
        return 10;
    else if ( insertions < 2048 && insertions >= 1024)
        return 11;
    else if ( insertions < 4096 && insertions >= 2048)
        return 12;
    else if ( insertions < 8192 && insertions >= 4096)
        return 13;
    else if ( insertions < 16384 && insertions >= 8192)
        return 14;
    else if ( insertions < 32768 && insertions >= 16384)
        return 15;
}

AVLTree::Node * AVLTree :: getRoot()
{
    return root;
}
