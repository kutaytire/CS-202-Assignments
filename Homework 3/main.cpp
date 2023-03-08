/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: main file
*/

#include <iostream>
#include <sstream>
#include <string>
#include "process.h"
using namespace std;

int main(int argc, char** argv) {

    string nameF = argv[1];

    Request * requests = createRequests(nameF);
    int requiredCompCount;
    int sizeOf, sumTime;
    string limitS = argv[2];



    int limit;
    stringstream ss;
    ss << limitS;
    ss >> limit;

    double average;
    operate(requiredCompCount, limit, sizeOf, sumTime, average, nameF);
    print(requiredCompCount, limit, sizeOf, sumTime, average, nameF);

    delete [] requests;


    return 0;

}


