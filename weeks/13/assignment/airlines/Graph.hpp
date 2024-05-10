#ifndef GRAPH_H
#define GRAPH_H

#include <string>

class Graph {
    private:
        std::string* airPorts;
        int** adjacencyMatrix;
        int numVerticies;
        // int* weightArray;
        // int* vertexSet;
        // int headVertexIndex;
        // int currentVertexIndex;

    public:
        Graph(void);
        Graph(int);
        void dijkstra(int);
        //int** getMatrix(void);
        int getCost(int, int);
        void setEdge(int, int, int);
        std::string getAirport(int);
        void setAirport(int, std::string);
        void displayGraph(void);
};

#endif