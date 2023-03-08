
/*
* Title: Sorting and Algorithm Efficiency
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 1
* Description: This is the sorting.cpp file. In this file, the sorting algorithms are implemented as well as the algorithms to create the arrays.
More importantly, the performanceAnalysis() method is here which systematically creates the arrays and calls the sorting algorithms.
*/


#include "sorting.h"
#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include <math.h>



void insertionSort(int *arr, const int size, int &compCount, int &moveCount) {

    for (int notSorted = 1; notSorted < size; notSorted++) {

        int element = arr[notSorted];

        moveCount = moveCount + 1;

        int index;

        for (index = notSorted; index > 0 && arr[index - 1] > element; index--) {

            arr[index] = arr[index - 1];
            moveCount = moveCount + 1;

            compCount = compCount + 1;

        }

        arr[index] = element;
        moveCount = moveCount + 1;

        if (index != 0) {
            compCount = compCount + 1;
        }


    }
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount) {

    bool isSorted = false;

	for (int pass = 1; (pass < size) && !isSorted; pass++) {

      isSorted = true;

      for (int index = 0; index < size - pass; index++) {

         if (arr[index] > arr[index + 1]) {

            swap(arr[index], arr[index + 1]);

            moveCount = moveCount + 3;
            isSorted = false;
         }

         compCount = compCount + 1;
      }


   }
}


void mergeSort(int *arr, const int size, int &compCount, int &moveCount) {

    mergeSort(arr, compCount, moveCount, 0, size - 1);

}

void quickSort(int *arr, const int size, int &compCount, int &moveCount) {


    quickSort(arr, compCount, moveCount, 0, size - 1);


}

void quickSort(int *arr, int &compCount, int &moveCount, int start, int end) {


   int pivot;

   if (start < end) {

      partitionArrays(arr, compCount, moveCount, start, end, pivot);

      quickSort(arr, compCount, moveCount, start, pivot - 1);

      quickSort(arr, compCount, moveCount, pivot + 1, end);
   }

}

void partitionArrays (int* arr, int& compCount, int& moveCount, int start, int last, int &pivotInd) {


    int pivot = arr[start];

    moveCount = moveCount + 1;

    int lastIndex = start;

    for (int firstUnknown = start + 1; firstUnknown <= last; ++firstUnknown) {

      if (arr[firstUnknown] < pivot) {

		  lastIndex++;
    	  swap(arr[firstUnknown], arr[lastIndex]);
    	  moveCount = moveCount + 3;
      }

      compCount++;
   }

   swap(arr[start], arr[lastIndex]);
   moveCount = moveCount + 3;
   pivotInd = lastIndex;

}



void mergeArrays (int* arr, int& compCount, int& moveCount, int start, int mid, int end) {


   int tempArray[end - start + 1];

   int first1 = start;
   int last1 = mid;
   int first2 = mid + 1;
   int last2 = end;
   int index = 0;

   for (;(first1 <= last1) && (first2 <= last2); index++) {

      if (arr[first1] < arr[first2]) {

         tempArray[index] = arr[first1];
         first1++;
      }

      else {

          tempArray[index] = arr[first2];
          first2++;
      }


      compCount++;
      moveCount++;
   }


   for (; first1 <= last1; first1++, index++) {

      tempArray[index] = arr[first1];
      moveCount++;
   }


   for (; first2 <= last2; first2++, index++) {

      tempArray[index] = arr[first2];
      moveCount++;
   }


   for (index = start; index <= end; index++) {

      arr[index] = tempArray[index - start];
      moveCount++;
   }


}



void mergeSort(int *arr,  int &compCount, int &moveCount, int start, int end) {

    if (start < end) {

          int mid = (start + end)/2;

          mergeSort(arr, compCount, moveCount, start, mid);

          mergeSort(arr, compCount, moveCount, mid + 1, end);

          mergeArrays(arr, compCount, moveCount, start, mid, end);
       }

}

void displayArray(const int *arr, const int size) {


    string result =  "The arrary is: {";

    for (int a = 0; a < size; a++) {

        string str;
        stringstream ss;
        ss << arr[a];
        ss >> str;


        result.append(str + ",");


    }

    result.erase(result.length() - 1, 1);
    result.append("}");

    cout << result << endl;


}

void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {

    srand(time(NULL));

    arr1 = new int [size];
    arr2 = new int [size];
    arr3 = new int [size];
    arr4 = new int [size];


    for (int i = 0; i < size; i++) {

        arr1[i] = rand() % RAND_MAX;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
        arr4[i] = arr1[i];
    }



}

void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {


    srand(time(NULL));


    arr1 = new int [size];
    arr2 = new int [size];
    arr3 = new int [size];
    arr4 = new int [size];




    for (int i = 0; i < size; i++) {

        arr1[i] = i;
    }

    for ( int a = 0;  a < size / 20; a++) {

        int i = rand() % size;
        int j = rand() % size;
        swap(arr1[i], arr1[j]);

    }



    for (int k = 0; k < size; k++) {

        arr2[k] = arr1[k];
        arr3[k] = arr1[k];
        arr4[k] = arr1[k];
    }


}

void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size) {


    srand(time(NULL));


    arr1 = new int [size];
    arr2 = new int [size];
    arr3 = new int [size];
    arr4 = new int [size];

    for (int i = size - 1; i >= 0; i--) {

        arr1[size - 1 - i] = i;
    }

    for ( int a = 0;  a < size / 20; a++) {

        int i = rand() % size;
        int j = rand() % size;
        swap(arr1[i], arr1[j]);

    }

    for (int k = 0; k < size; k++) {

        arr2[k] = arr1[k];
        arr3[k] = arr1[k];
        arr4[k] = arr1[k];
    }


}


void performanceAnalysis() {


    int movIns = 0;
    int compIns = 0;
    double insArr[32];
    double bubArr[32];
    double mergeArr[32];
    double quickArr[32];

    cout << "  For randomly created arrays: array size, elapsed time, comparison count and move count are below." << endl;

    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;

    double duration;

    for (int size = 5000; size <= 40000; size = size + 5000) {

        int* arr1;
        int* arr2;
        int* arr3;
        int* arr4;

        createRandomArrays(arr1, arr2, arr3, arr4, size);



        clock_t startTime1 = clock();

        insertionSort(arr1, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime1 ) / CLOCKS_PER_SEC;

        insArr[a] = movIns;
        insArr[b] = compIns;
        insArr[c] = duration;
        insArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr1;

        clock_t startTime2 = clock();

        bubbleSort(arr2, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime2 ) / CLOCKS_PER_SEC;

        bubArr[a] = movIns;
        bubArr[b] = compIns;
        bubArr[c] = duration;
        bubArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr2;

        clock_t startTime3 = clock();

        mergeSort(arr3, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime3 ) / CLOCKS_PER_SEC;

        mergeArr[a] = movIns;
        mergeArr[b] = compIns;
        mergeArr[c] = duration;
        mergeArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr3;

        clock_t startTime4 = clock();

        quickSort(arr4, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime4 ) / CLOCKS_PER_SEC;

        quickArr[a] = movIns;
        quickArr[b] = compIns;
        quickArr[c] = duration;
        quickArr[d] = size;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

        delete []arr4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Insertion Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << insArr[d];
        cout.width(25); cout << left << insArr[c];
        cout.width(20); cout << left << (int) insArr[b];
        cout.width(20); cout << left << (int) insArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Bubble Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << bubArr[d];
        cout.width(25); cout << left << bubArr[c];
        cout.width(20); cout << left << (int) bubArr[b];
        cout.width(20); cout << left << (int) bubArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Merge Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << mergeArr[d];
        cout.width(25); cout << left << mergeArr[c];
        cout.width(20); cout << left << (int) mergeArr[b];
        cout.width(20); cout << left << (int) mergeArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Quick Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << quickArr[d];
        cout.width(25); cout << left << quickArr[c];
        cout.width(20); cout << left << (int) quickArr[b];
        cout.width(20); cout << left << (int) quickArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    cout << endl;
    cout << endl;



    cout << "  For almost sorted created arrays: array size, elapsed time, comparison count and move count are below." << endl;

     a = 0;
     b = 1;
     c = 2;
     d = 3;

    for (int size = 5000; size <= 40000; size = size + 5000) {

        int* arr1;
        int* arr2;
        int* arr3;
        int* arr4;

        createAlmostSortedArrays(arr1, arr2, arr3, arr4, size);

        clock_t startTime5 = clock();

        insertionSort(arr1, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime5 ) / CLOCKS_PER_SEC;

        insArr[a] = movIns;
        insArr[b] = compIns;
        insArr[c] = duration;
        insArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr1;

        clock_t startTime6 = clock();

        bubbleSort(arr2, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime6 ) / CLOCKS_PER_SEC;

        bubArr[a] = movIns;
        bubArr[b] = compIns;
        bubArr[c] = duration;
        bubArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr2;

        clock_t startTime7 = clock();

        mergeSort(arr3, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime7 ) / CLOCKS_PER_SEC;

        mergeArr[a] = movIns;
        mergeArr[b] = compIns;
        mergeArr[c] = duration;
        mergeArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr3;

        clock_t startTime8 = clock();

        quickSort(arr4, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime8 ) / CLOCKS_PER_SEC;

        quickArr[a] = movIns;
        quickArr[b] = compIns;
        quickArr[c] = duration;
        quickArr[d] = size;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

        delete []arr4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Insertion Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << insArr[d];
        cout.width(25); cout << left << insArr[c];
        cout.width(20); cout << left << (int) insArr[b];
        cout.width(20); cout << left << (int) insArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Bubble Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << bubArr[d];
        cout.width(25); cout << left << bubArr[c];
        cout.width(20); cout << left << (int) bubArr[b];
        cout.width(20); cout << left << (int) bubArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Merge Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << mergeArr[d];
        cout.width(25); cout << left << mergeArr[c];
        cout.width(20); cout << left << (int) mergeArr[b];
        cout.width(20); cout << left << (int) mergeArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Quick Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << quickArr[d];
        cout.width(25); cout << left << quickArr[c];
        cout.width(20); cout << left << (int) quickArr[b];
        cout.width(20); cout << left << (int) quickArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    cout << endl;
    cout << endl;

    cout << "  For almost unsorted created arrays: array size, elapsed time, comparison count and move count are below." << endl;

     a = 0;
     b = 1;
     c = 2;
     d = 3;

    for (int size = 5000; size <= 40000; size = size + 5000) {

        int* arr1;
        int* arr2;
        int* arr3;
        int* arr4;

        createAlmostUnsortedArrays(arr1, arr2, arr3, arr4, size);

        clock_t startTime9 = clock();

        insertionSort(arr1, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime9 ) / CLOCKS_PER_SEC;

        insArr[a] = movIns;
        insArr[b] = compIns;
        insArr[c] = duration;
        insArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr1;

        clock_t startTime10 = clock();

        bubbleSort(arr2, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime10 ) / CLOCKS_PER_SEC;

        bubArr[a] = movIns;
        bubArr[b] = compIns;
        bubArr[c] = duration;
        bubArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr2;

        clock_t startTime11 = clock();

        mergeSort(arr3, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime11 ) / CLOCKS_PER_SEC;

        mergeArr[a] = movIns;
        mergeArr[b] = compIns;
        mergeArr[c] = duration;
        mergeArr[d] = size;

        movIns = 0;
        compIns = 0;

        delete []arr3;

        clock_t startTime12 = clock();

        quickSort(arr4, size, compIns, movIns);

        duration = 1000 * double( clock() - startTime12 ) / CLOCKS_PER_SEC;

        quickArr[a] = movIns;
        quickArr[b] = compIns;
        quickArr[c] = duration;
        quickArr[d] = size;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

        delete []arr4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Insertion Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << insArr[d];
        cout.width(25); cout << left << insArr[c];
        cout.width(20); cout << left << (int) insArr[b];
        cout.width(20); cout << left << (int) insArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Bubble Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << bubArr[d];
        cout.width(25); cout << left << bubArr[c];
        cout.width(20); cout << left << (int) bubArr[b];
        cout.width(20); cout << left << (int) bubArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Merge Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << mergeArr[d];
        cout.width(25); cout << left << mergeArr[c];
        cout.width(20); cout << left << (int) mergeArr[b];
        cout.width(20); cout << left << (int) mergeArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }

    a = 0;
    b = 1;
    c = 2;
    d = 3;

    cout << "  ------------------------------------------------------------------------------------------------" << endl;
    cout << "  Analysis of Quick Sort" << endl;

    cout.width(20); cout << left << "  Array Size";
    cout.width(25); cout << left << "  Elapsed Time (in ms)";
    cout.width(20); cout << left << "  Comparison Count";
    cout.width(20); cout << left << "  Move Count";
    cout << endl;

    for (int k = 0; k < 8; k++){

        cout << "  ";
        cout.width(20); cout << left << quickArr[d];
        cout.width(25); cout << left << quickArr[c];
        cout.width(20); cout << left << (int) quickArr[b];
        cout.width(20); cout << left << (int) quickArr[a];
        cout << endl;

        a = a + 4;
        b = b + 4;
        c = c + 4;
        d = d + 4;

    }












}






