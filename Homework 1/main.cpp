

/*
* Title: Sorting and Algorithm Efficiency
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 1
* Description: This is the main where the sorting of the arrays are made and the performanceAnalysis() method is called.
*/

#include <math.h>

#include <iostream>

#include "sorting.h"

using namespace std;

int main() {

    cout << endl;
    cout << endl;

    int mov = 0;
    int com = 0;

    int arr1 [16] =  {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};

    const int size1 = 16;
    const int size2 = 6;

    cout << "  Insertion Sort: " << endl;

    insertionSort(arr1, size1, com, mov);

    cout << "  Number of key comparisons: " << com << endl;
    cout << "  Number of moves: " << mov << endl;
    cout << "  Result of sort: ";
    displayArray(arr1, size1);

    cout << endl;

    int mov2 = 0;
    int com2 = 0;

    int arr2 [16] =  {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};

    cout << "  Bubble Sort: " << endl;

    bubbleSort(arr2, size1, com2, mov2);

    cout << "  Number of key comparisons: " << com2 << endl;
    cout << "  Number of moves: " << mov2 << endl;
    cout << "  Result of sort: ";
    displayArray(arr2, size1);

    cout << endl;

    int mov3 = 0;
    int com3 = 0;

    int arr3 [16] =  {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};

    // For my personal testing

    //int arr3 [16] =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    //int arr3 [16] =  {16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


    cout << "  Merge Sort: " << endl;

    mergeSort(arr3, size1, com3, mov3);

    cout << "  Number of key comparisons: " << com3 << endl;
    cout << "  Number of moves: " << mov3 << endl;
    cout << "  Result of sort: ";
    displayArray(arr3, size1);

    cout << endl;

    int mov4 = 0;
    int com4 = 0;

    int arr4 [16] =  {9, 6, 7, 16, 18, 5, 2, 12, 20, 1, 16, 17, 4, 11, 13, 8};


    cout << "  Quick Sort: " << endl;

    quickSort(arr4, size1, com4, mov4);

    cout << "  Number of key comparisons: " << com4 << endl;
    cout << "  Number of moves: " << mov4 << endl;
    cout << "  Result of sort: ";
    displayArray(arr4, size1);


    cout << endl;
    cout << endl;


    performanceAnalysis();




    return 0;

}
