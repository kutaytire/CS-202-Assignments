

hw4: FlightGraph.o main.o
	g++ main.o FlightGraph.o -o hw4

main.o: main.cpp FlightGraph.h
	g++ -c main.cpp

FlightGraph.o: FlightGraph.cpp FlightGraph.h
	g++ -c FlightGraph.cpp

clean:
	rm *.o

