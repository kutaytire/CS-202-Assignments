/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: computer implementation file
*/

#include "Computer.h"
#include <iostream>
using namespace std;


Computer :: Computer() {

    endTime = 0;
}

Computer :: Computer(int time) {

    endTime = time;
}

int Computer:: getEndTime() {

    return endTime;
}

bool Computer:: isEmpty(int time) {

    return time >= endTime;
}

void Computer :: process( Request req, int time, int *& arr, int count) {

    endTime = req.getProcessTime() + time;
    arr[count] = time - req.getSendTime();

}

void Computer :: print( Request req, int time, int count) {

    endTime = req.getProcessTime() + time;

    cout << "Computer " << id << " takes request " << req.getId() << " at ms " << time << " (wait: " << time - req.getSendTime() << " ms)" << endl;

}

void Computer :: setId(int ide) {

    id = ide;

}

