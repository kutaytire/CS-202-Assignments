/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description: Implementation of BST methods.
*/


#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree:: BinarySearchTree() {

    root = NULL;
}

BinarySearchTree:: ~BinarySearchTree() {

    deleteTree(root);

}

BinarySearchTree::BinarySearchTree(const int &rootItem) {

    root = new BinaryNode(rootItem);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & originalTree) {

    root = copyTree(originalTree.root);
}

void BinarySearchTree::deleteTree(BinaryNode * &root){

		if (root != NULL){
			deleteTree(root->leftChildPtr);
			deleteTree(root->rightChildPtr);
			delete root;
			root = NULL;
		}
}

BinaryNode * BinarySearchTree::copyTree(BinaryNode *tree) {

    BinaryNode* newTree = NULL;
    if (tree != NULL) {

        newTree = new BinaryNode(tree->item, copyTree(tree->leftChildPtr), copyTree(tree->rightChildPtr), tree ->parent, tree -> size);
    }
    return newTree;
}

bool BinarySearchTree:: isEmpty() {

    return root == NULL;
}

int BinarySearchTree::getHeight() {

    BinaryNode * start = root;
    return recursiveHeight(start);


}

int BinarySearchTree:: recursiveHeight(BinaryNode* & nodePtr) {


    if (nodePtr == NULL) {

        return 0;
    }

    else {

        return 1 + max(recursiveHeight(nodePtr -> leftChildPtr), recursiveHeight(nodePtr -> rightChildPtr) );
    }


}

int BinarySearchTree::getNumberOfNodes() {

    int count = 0;
    BinaryNode * start = root;

    recursiveCountNodes(count, start);

    return count;


}

void BinarySearchTree::recursiveCountNodes(int& totalCount, BinaryNode* & nodePtr) {

    if (nodePtr == NULL) {

        return;
    }

    else {

        recursiveCountNodes(totalCount, nodePtr -> leftChildPtr);
        totalCount++;
        recursiveCountNodes(totalCount, nodePtr -> rightChildPtr);
    }


}

bool BinarySearchTree::add(int newEntry) {

    BinaryNode * start = root;

    if (contains( newEntry)) {

        return false;
    }

    if (root == NULL) {

        root = new BinaryNode(newEntry, NULL, NULL, NULL, 0);

        return true;
    }


    if (newEntry <= 0) {

        return false;
    }

    else {


        if (newEntry > root -> item) {

            addRecursively(root, root -> rightChildPtr, newEntry);
            root -> size++;
            return true;
        }

        else if (newEntry < root -> item) {

            addRecursively(root, root -> leftChildPtr, newEntry);
            /*
            cout << "added: " << newEntry<< endl;
            cout << "parent: " << start<< endl;
            cout << "node: " << left<< endl;
            cout << "left2: " << root -> leftChildPtr << endl;
            */
            root -> size++;
            return true;
        }

        else {

            return false;
        }
    }

}

void BinarySearchTree::addRecursively(BinaryNode *& parent, BinaryNode *& ptr, int& entry) {

    if (ptr == NULL) {


        ptr = new BinaryNode(entry, NULL, NULL, parent, 1);



    }

    else {
        if (entry < ptr->item) {



            if (parent -> rightChildPtr == ptr) {

                ptr -> size++;
                addRecursively(parent -> rightChildPtr, ptr->leftChildPtr, entry);
            }

            else {

                ptr -> size++;
                addRecursively(parent -> leftChildPtr, ptr->leftChildPtr, entry);
            }
        } else {

            if (parent -> rightChildPtr == ptr) {

                ptr -> size++;
                addRecursively(parent -> rightChildPtr, ptr->rightChildPtr, entry);
            }

            else {

                ptr -> size++;
                addRecursively(parent -> leftChildPtr, ptr-> rightChildPtr, entry);
            }

        }
    }

}

bool BinarySearchTree::remove(int anEntry) {

		return searchPoint(root, anEntry);
}


bool BinarySearchTree:: searchPoint(BinaryNode*& ptr, int anEntry){

    if (!contains(anEntry)) {

        return false;

    } else {

        if (ptr->item == anEntry) {

            ptr -> size--;
            deleteNode(ptr);


        } else if (anEntry < ptr->item){

            ptr-> size--;
            searchPoint(ptr->leftChildPtr, anEntry);

        } else {

            ptr-> size--;
            searchPoint(ptr->rightChildPtr, anEntry);
        }

        return true;
    }
}


void BinarySearchTree::deleteNode(BinaryNode *&ptr){

    BinaryNode* delPtr;
    int repItem;

    if ((ptr->leftChildPtr == NULL) && (ptr->rightChildPtr == NULL)) {


        delete ptr;
        ptr = NULL;

    } else if(ptr->leftChildPtr == NULL){

        delPtr = ptr;
        ptr = ptr->rightChildPtr;
        ptr -> parent = delPtr -> parent;
        delPtr->rightChildPtr = NULL;
        delete delPtr;



    } else if(ptr->rightChildPtr == NULL){

        delPtr = ptr;
        ptr = ptr->leftChildPtr;
        ptr -> parent = delPtr -> parent;
        delPtr->leftChildPtr = NULL;
        delete delPtr;

    }  else {


        processLeftmost(ptr->rightChildPtr, repItem);
        ptr->item = repItem;
    }
}

void BinarySearchTree::processLeftmost(BinaryNode *&ptr, int& item){

		if (ptr->leftChildPtr == NULL) {

			item = ptr->item;
			BinaryNode *delPtr = ptr;
			ptr = ptr->rightChildPtr;

			if (ptr != NULL) {

                ptr -> parent = delPtr -> parent;
			}

			delPtr->rightChildPtr = NULL; // defense
			delete delPtr;
		}
		else {

            ptr -> size--;
			processLeftmost(ptr->leftChildPtr, item);
		}
}


bool BinarySearchTree::contains(int anEntry) {

    BinaryNode *tem = root;

    while (tem != NULL) {

        if (tem ->item == anEntry) {

            return true;
        }
        else {
            if (anEntry < tem -> item ) {

                tem = tem->leftChildPtr;
            }
            else {

                tem = tem->rightChildPtr;
            }
        }
    }
    return false;
}

void BinarySearchTree::inorderTraverse() {

    BinaryNode* start = root;
    recursiveTraverse(start);
    cout << endl;


}

void BinarySearchTree::recursiveTraverse(BinaryNode* ptr) {

    if (ptr != NULL) {


        recursiveTraverse( ptr -> leftChildPtr);
        cout << ptr -> item << " ";

        /*
        cout << "size: " << ptr -> size << endl;

        if (ptr -> parent != NULL)
        cout << "Parent: " << ptr -> parent -> item << endl;

        if (ptr -> leftChildPtr != NULL) {
            cout << "Left Child: " << ptr -> leftChildPtr -> item << endl;
        }
        if (ptr ->rightChildPtr != NULL) {
            cout << "Right Child: " << ptr -> rightChildPtr -> item << endl;
        }

        cout << "-----------------" << endl;
        */

        recursiveTraverse( ptr -> rightChildPtr);

    }


}

int BinarySearchTree :: getWidth() {

    int height = getHeight();
    int width = 1;

    for (int k = 1; k <= height; k++) {

        int tmp = recursiveWidth(root, k);
        if (tmp > width) {

            width = tmp;

        }
    }

    return width;

}

int BinarySearchTree :: recursiveWidth(BinaryNode * ptr, int treeLevel) {

    if (ptr == NULL)
        return 0;

    if (treeLevel == 1)
        return 1;

    else if ( treeLevel > 1) {
        return recursiveWidth(ptr->leftChildPtr, treeLevel - 1) + recursiveWidth( ptr-> rightChildPtr, treeLevel - 1);
    }
}

int BinarySearchTree:: recursiveCount (BinaryNode* ptr, int start, int end){


    if (ptr == NULL){
        return 0;
    }
    if (ptr -> item <= end && ptr-> item >= start ){

        int left = recursiveCount(ptr -> leftChildPtr, start, end);
        int right = recursiveCount(ptr -> rightChildPtr, start, end);
        return left + right + 1;
    }
    else if (ptr-> item > end){

        int inLeft  = recursiveCount(ptr-> leftChildPtr, start, end);
        return inLeft;
    }
    else{

        int inRight = recursiveCount(ptr-> rightChildPtr, start, end);
        return inRight;
    }
}

int BinarySearchTree :: count(int a, int b) {


    BinaryNode* first = root;
    return recursiveCount(first, a, b);
}

int* BinarySearchTree:: createSortedArray() {

    int sizeArray = getNumberOfNodes();

    if (sizeArray == 0) {

        return NULL;
    }

    else {

        int* arr = new int [sizeArray];
        BinaryNode* start = root;
        int index = 0;
        formArray(arr, index, start);
        return arr;
    }


}

void BinarySearchTree:: formArray(int *arr, int &index, BinaryNode* & ptr){

    if (ptr == NULL) {
        return;
    }

    formArray(arr, index, ptr->leftChildPtr);

    arr[index] = ptr->item;
    index++;

    formArray(arr, index, ptr->rightChildPtr);
}

int BinarySearchTree:: select(int anEntry) {

    int * sorted = createSortedArray();
    int sizeArray = getNumberOfNodes();
    int result = -1;

    for (int k = 0; k < sizeArray; k++) {


        if (sorted[k] == anEntry) {

            result = k;
        }
    }

    delete [] sorted;
    return result;

}


int BinarySearchTree:: successor(int anEntry) {


    int * sorted = createSortedArray();
    int sizeArray = getNumberOfNodes();
    int result = -1;

    for (int k = 0; k < sizeArray; k++) {


        if (sorted[k] == anEntry) {

            if (k + 1 != sizeArray) {

                result = sorted[k + 1];
            }

            else {
                result = -2;
            }
        }
    }

    delete [] sorted;
    return result;

}
