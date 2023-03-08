
/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description: Header file for BinaryNode methods and variables
*/

#ifndef BinaryNode_h
#define BinaryNode_h

#include <stdio.h>

class BinaryNode{
private:


    int item;
    int size;
    BinaryNode * parent;
    BinaryNode * leftChildPtr;
    BinaryNode * rightChildPtr;

    BinaryNode();
    BinaryNode(const int& nodeItem);
    BinaryNode( const int& nodeItem, BinaryNode* left, BinaryNode* right, BinaryNode* theParent, int sizeOf);

    friend class BinarySearchTree;
};

#endif
