#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    Graph graph;
    if (!graph.readFromFile("graph2.dat")) {
        return 1;
    }

    int startVertex = 1;
    int numIterations = 100;
    int numAnts = 10;

    int bestLen = graph.ants(startVertex, numIterations, numAnts);

    cout << "Кратчайший гамильтонов цикл графа: " << bestLen << endl;

    return 0;
}