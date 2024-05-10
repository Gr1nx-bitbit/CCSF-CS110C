#include "Graph.hpp"
#include <iostream>
using namespace std;

int main(void) {
    Graph airline(6);
    airline.setEdge(0,1,120);
    airline.setEdge(0,2,150);
    airline.setEdge(0,5,500);
    airline.setEdge(0,1,120);
    airline.setEdge(1,0,120);
    airline.setEdge(1,3,75);
    airline.setEdge(1,5,350);
    airline.setEdge(2,0,150);
    airline.setEdge(2,4,250);
    airline.setEdge(3,1,75);
    airline.setEdge(3,4,150);
    airline.setEdge(4,2,250);
    airline.setEdge(4,3,150);
    airline.setEdge(5,0,500);
    airline.setEdge(5,1,350);

    airline.setAirport(0, "SFO");
    airline.setAirport(1, "LAX");
    airline.setAirport(2, "LAS");
    airline.setAirport(3, "PHX");
    airline.setAirport(4, "DEN");
    airline.setAirport(5, "JFK");
    
    cout << "Cheapest cost for a flight to every other airport from " << airline.getAirport(0) << endl;
    airline.dijkstra(0);
    cout << endl;

    cout << "Cheapest cost for a flight to every other airport from " << airline.getAirport(2) << endl;
    airline.dijkstra(2);

    //airline.displayGraph();
    return 0;
}