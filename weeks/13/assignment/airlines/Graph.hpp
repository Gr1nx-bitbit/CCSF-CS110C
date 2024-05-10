#ifndef GRAPH_H
#define GRAPH_H

class Graph {
    private:
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
        void displayGraph(void);
};

#endif