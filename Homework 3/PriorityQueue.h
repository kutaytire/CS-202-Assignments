/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: PriorityQueue headder file
*/

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "Request.h"
#include "Heap.h"

class PriorityQueue {
public:


	bool pqIsEmpty();
	void pqInsert(const Request& newItem);
	void pqDelete(Request& priorityItem);

private:
	Heap h;
};

#endif
