/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: Request implemetation file
*/

#include "Request.h"
#include <iostream>
using namespace std;

    Request:: Request(int reqid, int reqpri, int reqsend, int reqpro) {

        id = reqid;
        priority = reqpri;
        sendTime = reqsend;
        processTime = reqpro;

    }

    Request:: Request() {

        id = 0;
        priority = 0;
        sendTime = 0;
        processTime = 0;

    }

    Request Request::getRequest() {

        return *this;

    }

    int Request:: getId() {

        return id;
    }

    int Request:: getPriority() {

        return priority;
    }

    int Request:: getSendTime() {

        return sendTime;
    }

    int Request:: getProcessTime() {

        return processTime;
    }

