/*
* Title: CS202 Spring 2022
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 4
* FlightGraph.cpp where the method implementations can be found.
*/

#include "FlightGraph.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

FlightGraph:: FlightGraph(string fileName) {

    sizeOf = getSize(fileName);
    airportList = new AirportNode*[sizeOf];

    for (int a = 0; a < sizeOf; a++) {

        airportList[a] = NULL;
    }
}

FlightGraph :: ~FlightGraph() {

     for (int k = 0; k < sizeOf; k++) {

        while (airportList[k] != NULL) {

             AirportNode* temp = airportList[k];
             airportList[k] = airportList[k] -> next;
             temp->next = NULL;
             delete temp;

        }

    }

    delete [] airportList;

}

int FlightGraph :: getSize(string fileName) {

    string input;

    ifstream inputFile(fileName.c_str());
    getline(inputFile, input);

    int size;
    stringstream ss;
    ss << input;
    ss >> size;

    return size;

}

void FlightGraph :: insertion(int airport1, int airport2, int duration) {


    AirportNode* newNode = new AirportNode;
    newNode -> airport = airport2;
    newNode -> durationOf = duration;

    newNode -> next = airportList[airport1];
    airportList[airport1] = newNode;


    AirportNode* newNode2 = new AirportNode;
    newNode2 -> airport = airport1;
    newNode2 -> durationOf = duration;

    newNode2 -> next = airportList[airport2];
    airportList[airport2] = newNode2;


    AirportNode * cur = airportList[airport1];
    int count = 0;

    while(cur != NULL) {

        count++;
        cur = cur -> next;

    }

    cout << "Inserted a new flight between " << airport1 << " and " << airport2 << "." << endl;
    cout << "   The number of flights from " << airport1 << " is " << count << endl;
    cout << endl;

}

void FlightGraph :: listFlights(int airport) {

    AirportNode * cur = airportList[airport];
    int countOf = 0;

    cout << "List of all flights from " << airport << ": " << endl;

    while (cur != NULL) {


        cout << "   " << airport << " to " << cur -> airport << " with a duration of " << cur -> durationOf << "." << endl;
        cur = cur -> next;
        countOf++;

    }

    cout << "   " << "The number of flights is " << countOf << endl;
    cout << endl;

}

/*

This algorithm works recursively by taking the beginning airport and finding the smallest connected to that one.
Going recursively if it reaches the targeted airport, it saves the path as minimum path. After that it traverses
other paths recursively and when finds a shorter path, updates both the minimum and the minimum path. It uses the same
logic with the shortest path algorithm in the slides. The only difference is instead of creating a 2D weight array and updating
the array constantly, it recursively finds the minimum without needing to update other irrelevant paths.

*/

void FlightGraph :: shortestPath(int airport1, int airport2) {

    int minimum = 2147483647;
    int finalSize = 0;

    int* visited = new int[sizeOf];
    for (int a = 0; a < sizeOf; a++) {

        visited[a] = 0;

    }

    int** elements = new int*[sizeOf];
    for ( int i = 0; i < sizeOf; i++) {

        elements[i] = new int[3];
    }

    for(int i = 0; i < sizeOf; i++) {

        for(int k = 0; k < 3; k++){

            elements[i][k] = 0;
        }
    }

    int** minPath = new int*[sizeOf];

    for ( int i = 0; i < sizeOf; i++) {

        minPath[i] = new int[3];
    }

    for(int i = 0; i < sizeOf; i++) {

        for(int k = 0; k < 3; k++){

            minPath[i][k] = 0;
        }
    }

    visited[airport1] = 1;
    recursiveHelper(airport1, airport2, visited, 0, minimum, elements, minPath, 0, finalSize);

    if (minimum == 2147483647) {

        cout << "No path is found from " << airport1 << " to " << airport2 << endl;
        cout << endl;
    }

    else {

        cout << "Shortest path from " << airport1 << " to " << airport2 << ": " << endl;
        for (int k = 0; k < finalSize; k++) {

            cout << "   " << minPath[k][0] << " to " << minPath[k][1] << " with a duration of " << minPath[k][2] << endl;
        }

        cout << "   Total flight duration of path: " << minimum << "." << endl;
        cout << endl;
    }

     for (int k = 0; k < sizeOf; k++) {

        delete [] elements [k];
    }

    delete [] elements;

     for (int k = 0; k < sizeOf; k++) {

        delete [] minPath[k];
    }

    delete [] minPath;
    delete [] visited;


}

void FlightGraph :: recursiveHelper(int airport1, int airport2, int* & visited, int sum, int& minimum, int** & elements, int** & minPath, int count, int&finalSize) {

    if (airport1 == airport2) {

        visited[airport2] = 0;

        if (sum < minimum) {

            minimum = sum;
            finalSize = count;

            for(int i = 0; i < count; i++){

                for(int b = 0; b < 3; b++) {

                    minPath[i][b] = elements[i][b];
                }
            }
        }

        return;
    }

    AirportNode * cur = airportList[airport1];

    while (cur != NULL) {

        if (visited[cur -> airport] == 0) {

            visited[cur -> airport] = 1;
            elements[count][0] = airport1;
            elements[count][1] = cur -> airport;
            elements[count][2] = cur -> durationOf;
            recursiveHelper(cur -> airport, airport2, visited, sum + cur -> durationOf, minimum, elements, minPath, count + 1, finalSize);

        }

        cur = cur -> next;
    }

    elements[count][0] = 0;
    elements[count][1] = 0;
    elements[count][2] = 0;

    visited[airport1] = 0;

}

void FlightGraph :: minimizeCosts() {

    int visited [sizeOf];
    for (int a = 0; a < sizeOf; a++) {

        visited[a] = 0;
    }

    AirportNode** newList = new AirportNode*[sizeOf];

    for (int k = 0; k < sizeOf; k++) {

        newList[k] = NULL;
    }

    visited[0] = 1;

    bool done = false;

    int totalBefore = 0;
    int totalAfter = 0;

    for (int a = 0; a < sizeOf; a++) {

        AirportNode * cur1 = airportList[a];

        while( cur1 != NULL){

            totalBefore = totalBefore + cur1 -> durationOf;
            cur1 = cur1 -> next;
        }

    }

    while(!done) {


        int minimum = 2147483647;

        int from = -1;
        int to = -1;

        for(int index = 0; index < sizeOf; index++){

            if(visited[index] == 1) {

                AirportNode * cur = airportList[index];

                while(cur != NULL) {

                    if(visited[cur -> airport] == 0) {

                        if( cur -> durationOf < minimum) {

                            minimum = cur -> durationOf;
                            to = cur -> airport;
                            from = index;
                        }
                    }

                    cur = cur -> next;
                }
            }
        }

        if (to == -1) {

            for ( int c = 0; c < sizeOf; c++) {

                if ( visited[c] == 0) {

                    visited[c] = 1;
                    break;
                }
            }

            for(int index = 0; index < sizeOf; index++){

                if(visited[index] == 1) {

                    AirportNode * cur = airportList[index];

                    while(cur != NULL) {

                        if(visited[cur -> airport] == 0) {

                            if( cur -> durationOf < minimum) {

                                minimum = cur -> durationOf;
                                to = cur -> airport;
                                from = index;
                            }
                        }

                        cur = cur -> next;
                    }
                }
            }

        }

        if (to != -1) {

            visited[to] = 1;

            AirportNode* newNode = new AirportNode;
            newNode -> airport = to;
            newNode -> durationOf = minimum;

            newNode -> next = newList[from];
            newList[from] = newNode;


            AirportNode* newNode2 = new AirportNode;
            newNode2 -> airport = from;
            newNode2 -> durationOf = minimum;

            newNode2 -> next = newList[to];
            newList[to] = newNode2;

        }

        done = true;

        for (int k = 0; k < sizeOf; k++) {

            if (visited[k] == 0) {

                done = false;
                break;
            }
        }
    }


    for (int k = 0; k < sizeOf; k++) {

        while (airportList[k] != NULL) {

             AirportNode* temp = airportList[k];
             airportList[k] = airportList[k] -> next;
             temp->next = NULL;
             delete temp;

        }

    }

    delete [] airportList;


    airportList = newList;


    for (int a = 0; a < sizeOf; a++) {

        AirportNode * cur1 = airportList[a];

        while( cur1 != NULL){

            totalAfter = totalAfter + cur1 -> durationOf;
            cur1 = cur1 -> next;
        }

    }

    cout << "Total cost of operations before minimization: " << totalBefore/2 << endl;
    cout << "Total cost of operations after minimization: " << totalAfter/2 << endl;

    cout << endl;


}

