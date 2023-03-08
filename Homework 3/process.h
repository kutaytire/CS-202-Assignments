/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: process headder file
*/

#include "PriorityQueue.h"
#include "Request.h"
#include <string>

using namespace std;

Request* createRequests(string  fileName);
void operate(int & minNumber, const int limit, int &sizeOf, int &sumTimer, double& averageT, string fileName);
void print(int  minNumber, const int limit, int sizeOf, int sumTime, double average, string fileName);
