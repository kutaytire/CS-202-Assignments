/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: Heap implementation file
*/

#include "Heap.h"
#include <iostream>
using namespace std;



Heap:: Heap() {

    items = new Request[MAX_HEAP_SIZE];
    size = 0;

}

Heap:: ~Heap() {

        delete [] items;
        size = 0;
}

bool Heap :: isEmpty() {

    return size == 0;

}

void Heap:: insertItem(Request value) {

    if (size >= MAX_HEAP_SIZE) {

        cout << "No place to insert!" << endl;
        return;
    }

    else {


        items[size] = value;
        int place = size;
        int parent = (place - 1) / 2;


        while (place > 0 && (items[place].getPriority() > items[parent].getPriority() || items[place].getPriority() == items[parent].getPriority() && items[place].getSendTime() < items[parent].getSendTime()) ) {

            Request temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;

        }

        size++;
    }


}

void Heap:: deleteItem(Request &deletedItem) {

    if (isEmpty()) {

        cout << "Empty" << endl;
    }

    else {

        deletedItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }


}

void Heap :: heapRebuild(int root) {

	int child = 2 * root + 1;
	if ( child < size ) {

		int rightChild = child + 1;

		if ( (rightChild < size) && items[rightChild].getPriority() > items[child].getPriority()){

			child = rightChild;
		}

		else if (  (rightChild < size) && items[rightChild].getPriority() == items[child].getPriority() && items[rightChild].getSendTime() < items[child].getSendTime() ){

			child = rightChild;
		}

		if ( items[root].getPriority() < items[child].getPriority() || (items[root].getPriority() == items[child].getPriority() && items[root].getSendTime() > items[child].getSendTime())) {
			Request temp = items[root];
			items[root] = items[child];
			items[child] = temp;


			heapRebuild(child);
		}

    }


}
