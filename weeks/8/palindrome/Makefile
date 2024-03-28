
main: main.o InfixToPostfixCalc.o Queue.o
	g++ main.o InfixToPostfixCalc.o Queue.o -o main

main.o: main.cpp
	g++ -c main.cpp

InfixToPostfixCalc.o: InfixToPostfixCalc.cpp
	g++ -c InfixToPostfixCalc.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

clean:
	rm *.o main