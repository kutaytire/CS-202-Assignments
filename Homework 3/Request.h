/*
* Title: Heaps, Priority Queues
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 3
* Description: Request headder file
*/
#ifndef Request_h
#define Request_h


class Request{

   public:

       Request(int reqid, int reqpri, int reqsend, int reqpro);
       Request();
      //~Request();

      Request getRequest();
      int getId();
      int getPriority();
      int getSendTime();
      int getProcessTime();

   private:

        int id;
        int priority;
        int sendTime;
        int processTime;


};

#endif

