/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: PriorityQueue implementation file
*/

#include "PriorityQueue.h"
#include <iostream>
using namespace std;


bool PriorityQueue:: pqIsEmpty(){
	return h.isEmpty();
}

void PriorityQueue:: pqInsert(const Request& newItem){

		h.insertItem(newItem);
}

void PriorityQueue::pqDelete(Request& priorityItem){

		h.deleteItem(priorityItem);
}
