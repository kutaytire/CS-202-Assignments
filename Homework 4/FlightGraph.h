/*
* Title: CS202 Spring 2022
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 4
* FlightGraph.h where the necessary methods and helpers are declared.
*/

#ifndef FlightGraph_h
#define FlightGraph_h

#include <string>
using namespace std;

class FlightGraph {

public:

    FlightGraph(string fileName);
    ~FlightGraph();
    void insertion(int airport1, int airport2, int duration);
    void listFlights(int airport);
    void shortestPath(int airport1, int airport2);
    void recursiveHelper(int airport1, int airport2, int* & visited, int sum, int& minimum, int** & elements, int** & minPath, int count, int& finalSize);
    void minimizeCosts();
    int getSize(string filename);

private:

     struct AirportNode{

        int airport;
        int durationOf;
        AirportNode* next;
    };

    AirportNode** airportList;
    int sizeOf;

};


#endif
