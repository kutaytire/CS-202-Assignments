
/*
* Title: Trees
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 2
* Description: Implementation of analyze method that adds random elements to tree and deletes them in random order.
*/
#include "BinarySearchTree.h"
#include "analyze.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void analyzeBST()
{
    int SIZE = 10000;
    int arr[SIZE];
    srand(time(NULL));
    BinarySearchTree bst;


    cout << "Random BST size vs. height (Insertion)" << endl;
    cout << "--------------------------------------" << endl;

    for (int i = 0; i < SIZE; i++) {

        arr[i] = rand() % RAND_MAX;
        bst.add(arr[i]);

        if (i % 100 == 0)
        {
            cout << bst.getNumberOfNodes() << " " << bst.getHeight() << endl;
        }
    }

    cout << "Random BST size vs. height (Deletion)" << endl;
    cout << "--------------------------------------" << endl;

    for (int i = 0; i > 0; i--)
    {
        int j = rand() % SIZE;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < 10000; i++)
    {
        bst.remove(arr[i]);
        if (i % 100 == 0)
        {
            cout << bst.getNumberOfNodes() << " " << bst.getHeight() << endl;
        }
    }

}

