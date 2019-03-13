/**
* Title : Heaps and AVL Trees
* Author : Faaiz Ul Haque
* ID: 21503527
* Section : 2
* Assignment : 3
* Description : AVL header file
*/
#ifndef AVLTREE_H
#define AVLTREE_H


class AVLTree
{
    private:


    public:
        struct Node
        {
            int item;
            Node * left;
            Node * right;
        };
        int insertions;
        Node * root;
        AVLTree();
        virtual ~AVLTree();
        void insert( int value);
        bool isBalanced( Node * curr, Node *&temp );
        int getHeight( Node * root );
        int getHeight();
        Node * getRoot ();
        void singleLR( Node * first, Node * second, Node * third);
        void singleRR( Node * first, Node * second, Node * third);
        void doubleLRR( Node * first, Node * second, Node * third );
        void doubleRLR( Node * first, Node * second, Node * third);

    protected:


};

#endif // AVLTREE_H
