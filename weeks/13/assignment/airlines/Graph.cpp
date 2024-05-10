#include "Graph.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

#define DEBUG

Graph::Graph(void) {
    adjacencyMatrix = nullptr;
    numVerticies = 0;
}

Graph::Graph(int numVerticies) {
    this->numVerticies = numVerticies;
    adjacencyMatrix = new int*[numVerticies];
    for (int i = 0; i < numVerticies; i++)
        adjacencyMatrix[i] = new int[numVerticies];
    for (int i = 0; i < numVerticies; i++) {
        for (int j = 0; j < numVerticies; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

int Graph::getCost(int iIndex, int jIndex) {

    if (           (iIndex < 0 || 0 > jIndex) 
                               || 
        (iIndex > numVerticies || numVerticies < jIndex)

        ) { cout << "Invalid indecies!" << endl; return -1; } 
    
    else return adjacencyMatrix[iIndex][jIndex];
    
}

void Graph::setEdge(int iIndex, int jIndex, int cost) {
    if (           (iIndex < 0 || 0 > jIndex) 
                               || 
        (iIndex > numVerticies || numVerticies < jIndex)

        )    cout << "Invalid indecies!" << endl;
    
    else adjacencyMatrix[iIndex][jIndex] = cost;
}

bool contains(int* array, int len, int value) {
    for (int i = 0; i < len; i++) {
        if (array[i] == value) {
            return true;
        }
    }
    return false;
}

void Graph::dijkstra(int headIndex) {
    int* vertexSet   = new int[numVerticies];
    int* weightSet   = new int[numVerticies];

    for (int i = 0; i < numVerticies; i++) {
        vertexSet[i] = -1;
    }

    // Step 1: initialize the vertex set and get the first set of data
    for (int index = 0; index < 1; index++) {
        vertexSet[index] = headIndex;
        int lowest = -1;
        int nextIndex;
        for (int i = 0; i < numVerticies; i++) {
            if (adjacencyMatrix[headIndex][i] != 0 && lowest == -1) {
                lowest = adjacencyMatrix[headIndex][i];
                nextIndex = i;
            } else if (adjacencyMatrix[headIndex][i] != 0 && adjacencyMatrix[headIndex][i] < lowest) {
                lowest = adjacencyMatrix[headIndex][i];
                nextIndex = i;
            }
            weightSet[i] = adjacencyMatrix[headIndex][i];
        }

        if ((index + 1) < numVerticies) {
            vertexSet[index + 1] = nextIndex;
        }
    }

    cout << "Weight set after initialize: " << endl;
    for (int i = 0; i < numVerticies; i++) {
        cout << "|" << setw(6) << weightSet[i] << setw(3);
    }
    cout << "|" << endl;

    for (int index = 1; index < numVerticies; index++) {
        int nextIndex;
        int lowest = -1;

        //update weightSet if there are any lower or possible edges
        for (int i = 0; i < numVerticies; i++) {
            if (!contains(vertexSet, numVerticies, i)) {
                if ((weightSet[i] == 0) && (weightSet[vertexSet[index]] != 0) && (adjacencyMatrix[vertexSet[index]][i] != 0) || (weightSet[i] > weightSet[vertexSet[index]] + adjacencyMatrix[vertexSet[index]][i]) && (weightSet[vertexSet[index]] != 0) && (adjacencyMatrix[vertexSet[index]][i] != 0) ) {
                    #ifndef DEBUG
                    cout << "previous weightSet[" << i << "]: " << weightSet[i] << endl;
                    cout << "weightSet[vertexSet[index]]: " << weightSet[vertexSet[index]] << " | vertexSet[index]: " << vertexSet[index] << endl;
                    cout << "setting weightSet[" << i << "]: " << weightSet[i] << " to weight[" << vertexSet[index] << "]: " <<  weightSet[vertexSet[index]] << " + adjacencyMatrix[" << vertexSet[index] << "][" << i << "]: " << adjacencyMatrix[vertexSet[index]][i] << " ––> " << adjacencyMatrix[vertexSet[index]][i] + weightSet[vertexSet[index]] << endl;
                    #endif
                    weightSet[i] = weightSet[vertexSet[index]] + adjacencyMatrix[vertexSet[index]][i];
                }
            }
        }

        //get the smallest connecting node and add it to the vertex set
        for (int i = 0; i < numVerticies; i++) {
            if (adjacencyMatrix[vertexSet[index]][i] != 0 && lowest == -1) {
                if (!contains(vertexSet, numVerticies, i)) {
                    #ifndef DEBUG
                    cout << "vertexSet[index]: " << vertexSet[index] << " | New lowest weight -> adjacencyMatrix[vertexSet[index]][i]: " << adjacencyMatrix[vertexSet[index]][i] << endl;
                    cout << "newIndex: " << i << endl << endl;
                    #endif
                    lowest = adjacencyMatrix[vertexSet[index]][i];
                    nextIndex = i;
                }
            } else if (adjacencyMatrix[vertexSet[index]][i] != 0 && adjacencyMatrix[vertexSet[index]][i] < lowest) {
                if (!contains(vertexSet, numVerticies, i)) {
                    #ifndef DEBUG
                    cout << "previous lowest: " << lowest << endl;
                    cout << "new lowest -> adjacencyMatrix[vertexSet[index]][i]" << adjacencyMatrix[vertexSet[index]][i] << endl;
                    cout << "newIndex: " << i << endl << endl;
                    #endif
                    lowest = adjacencyMatrix[vertexSet[index]][i];
                    nextIndex = i;
                }
            }
        }

        if (index + 1 < numVerticies) {
            for (int i = 0; i < index + 1; i++) {
                #ifndef DEBUG
                cout << "vertexSet[" << i << "]: " << vertexSet[i] << endl;
                #endif
            }
            #ifndef DEBUG
            cout << "setting vertexSet[" << index + 1 << "] to " << nextIndex << endl;
            #endif
            vertexSet[index + 1] = nextIndex;
        }
    }

    cout << "Weight set after Dijkstra's algorithm: " << endl;
    for (int i = 0; i < numVerticies; i++) {
        cout << "|" << setw(6) << weightSet[i] << setw(3);
    }
    cout << "|" << endl;

    // for (int i = 0; i < numVerticies; i++) {
    //         // so I have to check if the index I'm adding is in the vertex set, it would be nice to use a hash
    //         // map but that's too much work rn, I'll just do a brute force method
    //         int lowest = -1;
    //         int nextIndex;
    //         if (adjacencyMatrix[vertexSet[index]][i] != 0 && lowest == -1) {
    //             if (!contains(vertexSet, numVerticies, i)) {
    //                 lowest = adjacencyMatrix[vertexSet[index]][i];
    //                 nextIndex = i;
    //             }
    //         } else {
    //             if (adjacencyMatrix[vertexSet[index]][i] < lowest && adjacencyMatrix[vertexSet[index]][i] != 0) {
    //                 if (!contains(vertexSet, numVerticies, i)) {
    //                     lowest = adjacencyMatrix[vertexSet[index]][i];
    //                     nextIndex = i;
    //                 }
    //             }
    //         }
    //     }

}

void Graph::displayGraph(void) {
    for (int i = 0; i < numVerticies; i++) {
        for (int j = 0; j < numVerticies; j++) {
            cout << "|" << setw(6) << adjacencyMatrix[i][j] << setw(3);
        }
        cout << "|" << endl;
    }
}