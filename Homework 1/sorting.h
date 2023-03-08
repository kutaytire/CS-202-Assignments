

/*
* Title: Sorting and Algorithm Efficiency
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 1
* Description: This is the header file where the prototypes of the functions are defined.
*/
#include <math.h>

using namespace std;
#include <string>


void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);

void performanceAnalysis();


// Additional
void mergeArrays (int* arr, int& compCount, int& moveCount, int start, int mid, int end);
void mergeSort(int *arr,  int &compCount, int &moveCount, int start, int end);

void quickSort(int *arr, int &compCount, int &moveCount, int start,int end);
void partitionArrays (int* arr, int& compCount, int& moveCount, int start, int last, int &pivotInd);




