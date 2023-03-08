/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description: Methods for the BinarySearchTree methods.
*/
#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include "BinaryNode.h"

class BinarySearchTree {

public:

    BinarySearchTree();
    BinarySearchTree(const int& rootItem);
    BinarySearchTree(const BinarySearchTree & originalTree);
    ~BinarySearchTree();
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(int newEntry);
    bool remove(int anEntry);
    bool contains(int anEntry);
    void inorderTraverse();
    int getWidth();
    int count(int a, int b);
    int select(int anEntry);
    int successor(int anEntry);

    // Helpers

    void deleteTree(BinaryNode * &root);
    BinaryNode * copyTree(BinaryNode *tree);
    bool searchPoint(BinaryNode*& ptr, int anEntry);
    void processLeftmost(BinaryNode *&ptr, int& item);
    void deleteNode(BinaryNode *&ptr);
    int recursiveHeight(BinaryNode* & nodePtr);
    void recursiveCountNodes( int& totalCount, BinaryNode* & nodePtr);
    void addRecursively(BinaryNode *& parent, BinaryNode *& ptr, int& entry);
    void recursiveTraverse(BinaryNode* ptr);
    int recursiveWidth(BinaryNode * ptr, int treeLevel);
    int recursiveCount (BinaryNode* ptr, int start, int end);
    int* createSortedArray();
    void formArray(int *arr, int &index, BinaryNode* & ptr);


    bool insertItem(BinaryNode*& treePtr, const int& newEntry);
    // Properties

    BinaryNode * root;


};

#endif

