
simulator: Heap.o main.o Request.o Computer.o PriorityQueue.o process.o
	g++ main.o Heap.o Request.o Computer.o PriorityQueue.o process.o -o simulator

main.o: main.cpp process.h
	g++ -c main.cpp

process.o: process.cpp process.h
	g++ -c process.cpp

Request.o: Request.cpp Request.h
	g++ -c Request.cpp

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp

Computer.o: Computer.cpp Computer.h
	g++ -c Computer.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

clean:
	rm *.o
