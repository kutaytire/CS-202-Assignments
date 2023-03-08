/*
* Title: CS202 Spring 2022
* Author: Kutay Tire
* ID: 22001787
* Section: 3
* Assignment: 4
* Main.cpp where the file is read and the necessary methods are called.
*/

#include "FlightGraph.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {

    string fileName = argv[1];
    //string fileName = "test2.txt";
    FlightGraph fg(fileName);

    string input;
    string value;

    int airport1;
    int airport2;
    int duration;

    ifstream inputFile(fileName.c_str());

    getline(inputFile, input);
    getline(inputFile, input);

    int size;
    stringstream ss;
    ss << input;
    ss >> size;

    for (int k = 0; k < size; k++) {

        getline (inputFile, input);
        string * data = new string[(input.length()/2) + 1];

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


        if (data[0] == "I") {


            stringstream ss1;
            ss1 << data[1];
            ss1 >> airport1;

            stringstream ss2;
            ss2 << data[2];
            ss2 >> airport2;

            stringstream ss3;
            ss3 << data[3];
            ss3 >> duration;

            fg.insertion(airport1, airport2, duration);

        }

        else if (data[0] == "S") {


            stringstream ss1;
            ss1 << data[1];
            ss1 >> airport1;

            stringstream ss2;
            ss2 << data[2];
            ss2 >> airport2;

            fg.shortestPath(airport1, airport2);

        }

        else if (data[0] == "L") {

            stringstream ss1;
            ss1 << data[1];
            ss1 >> airport1;

            fg.listFlights(airport1);

        }

        else if (data[0][0] == 'M') {

            fg.minimizeCosts();
        }

        delete [] data;

    }


    return 0;
}
