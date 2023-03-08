/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: process implementation file
*/

#include "process.h"
#include "Computer.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Request* createRequests(string fileName) {

    string input;
    string value;

    int requestCount = 0;
    int id;
    int priority;
    int sendTime;
    int processTime;


    ifstream inputFile(fileName.c_str());
    getline(inputFile, input);

    int size;
    stringstream ss;
    ss << input;
    ss >> size;


    Request * requests = new Request[size];


    while (getline (inputFile, input)) {

        string *data = new string [4];

        int a = 0;
        int count = 0;

        while (a < input.length()) {

            while ( input[a] != ' ' && a < input.length()) {

                value = value + input[a];

                a++;
            }

            if ( value != "") {

                data[count] = value;
                count++;
            }
            a++;
            value = "";
        }

        stringstream ss1;
        ss1 << data[0];
        ss1 >> id;

        stringstream ss2;
        ss2 << data[1];
        ss2 >> priority;

        stringstream ss3;
        ss3 << data[2];
        ss3 >> sendTime;

        stringstream ss4;
        ss4 << data[3];
        ss4 >> processTime;

        Request req(id, priority, sendTime, processTime);
        requests[requestCount] = req;
        requestCount++;

        delete [] data;


    }



    inputFile.close();

    return requests;

}

void operate(int & minNumber, const int limit, int &sizeOf, int &sumTimer, double& averageT, string fileName) {

    Request * requests = createRequests(fileName);
    PriorityQueue pq;
    string input;
    int count;

    ifstream inputFile(fileName.c_str());
    getline(inputFile, input);

    int size;
    stringstream ss;
    ss << input;
    ss >> size;

    sizeOf = size;
    int * waitingTime = new int[size];
    int sumTime = 0;


    for (int n = 0; n < size; n++){

        sumTime = sumTime + requests[n].getProcessTime() + requests[n].getSendTime();
    }

    sumTimer = sumTime;

     for (int numberComp = 1; numberComp <= size; numberComp++) {

        Computer * comps = new Computer[numberComp];

        for (int c = 0; c < numberComp; c++) {

            comps[c].setId(c);

        }

        count = 0;

        for (int time = 0; time <= sumTime; time++) {

            for (int i = 0; i < size; i++) {

                if (requests[i].getSendTime() == time) {

                    pq.pqInsert(requests[i]);

                }
            }

            for ( int k = 0; k < numberComp; k++) {

                if (comps[k].isEmpty(time) && ! pq.pqIsEmpty()) {

                    Request req;
                    pq.pqDelete(req);

                    comps[k].process(req, time, waitingTime, count);

                    count++;
                }
            }


        }

        double sum = 0;
        double average = 0;

        for ( int b = 0; b < size; b++) {


            sum = sum + waitingTime[b];

        }

        average = sum / size;

        if (average < limit) {

            minNumber = numberComp;
            averageT = average;
            delete [] comps;
            break;
        }

        delete [] comps;
    }

    delete [] waitingTime;
    delete [] requests;


}

void print(int  minNumber, const int limit, int sizeOf, int sumTime, double average, string fileName) {

    Request * requests = createRequests(fileName.c_str());
    PriorityQueue pq;
    int count;

    cout << "Minimum number of computers required: " << minNumber << endl;
    cout << "Simulation with " << minNumber << " computers:" << endl;

    Computer * comps = new Computer[minNumber];

        for (int c = 0; c < minNumber; c++) {

            comps[c].setId(c);

        }

        count = 0;

        for (int time = 0; time <= sumTime; time++) {

            for (int i = 0; i < sizeOf; i++) {

                if (requests[i].getSendTime() == time) {

                    pq.pqInsert(requests[i]);

                }
            }

            for ( int k = 0; k < minNumber; k++) {

                if (comps[k].isEmpty(time) && ! pq.pqIsEmpty()) {

                    Request req;
                    pq.pqDelete(req);

                    comps[k].print(req, time, count);

                    count++;
                }
            }


        }

        cout << "Average waiting time: " << average << " ms" << endl;

        delete [] comps;
        delete [] requests;

}
