/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description: Implementation of BinaryNode constructor
*/

#include "BinaryNode.h"

// Default constructor
BinaryNode::BinaryNode(){};


BinaryNode :: BinaryNode( const int& nodeItem , BinaryNode* left, BinaryNode* right, BinaryNode* theParent, int sizeOf) {

    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    parent = theParent;
    size = sizeOf;
}

BinaryNode::BinaryNode(const int &nodeItem) {
    item = nodeItem;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    parent = NULL;
    size = 1;
}


