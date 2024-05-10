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
    airline.dijkstra(0);

    //airline.displayGraph();
    return 0;
}