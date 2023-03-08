/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: computer headder file
*/

#ifndef Computer_h
#define Computer_h
#include "Request.h"

class Computer{

   public:

       Computer();
       Computer(int time);
       int getEndTime();
       bool isEmpty(int time);
       void process( Request req, int time, int *& arr, int count);
       void print( Request req, int time, int count);
       void setId(int ide);

   private:

        int endTime;
        int id;


};

#endif
