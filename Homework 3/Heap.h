/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: Heap headder file
*/

#ifndef Heap_h
#define Heap_h
#include "Request.h"

const int MAX_HEAP_SIZE = 10000;

class Heap{

   public:

       Heap();
       ~Heap();

       bool isEmpty();
       void insertItem(Request value);
       void deleteItem(Request &deletedItem);

   protected:

       void heapRebuild(int root);

   private:

        int size;
        Request* items;


};

#endif
