#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    Graph graph;
    if (!graph.readFromFile("graph.dat")) {
        return 1;
    }

    int startVertex = 1;
    int endVertex = graph.getMaxVertex();
    int minDistance = graph.dijkstra(startVertex, endVertex);

    cout << "Кратчайшее расстояние от вершины " << startVertex << " до вершины " << endVertex << ": ";
    if (minDistance == -1) {
        cout << "нет пути" << endl;
    }
    else {
        cout << minDistance << endl;
    }

    return 0;
}