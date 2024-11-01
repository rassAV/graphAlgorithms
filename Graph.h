#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

struct edge {
    int to, weight;
    edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
    private:
    map<int, vector<edge>> graph;

    public:
    bool readFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cout << "Error! File not found!" << endl;
            return false;
        }

        int from, to, weight;
        while (infile >> from >> to >> weight) {
            addEdge(from, to, weight);
        }
        infile.close();
        return true;
    }

    void addEdge(int from, int to, int weight) {
        graph[from].emplace_back(edge(to, weight));
    }

    int getMaxVertex() const {
        int maxVertex = 0;
        for (const auto& pair : graph) {
            for (const auto& edge : pair.second) {
                if (edge.to > maxVertex) {
                    maxVertex = edge.to;
                }
            }
        }
        return maxVertex;
    }

    int dijkstra(int start, int end) {
        int minDistance = INTMAX_MAX;
        map<int, int> distances;
        distances[start] = 0;
        bool startFlag = false;

        for (const auto& pair : graph) {
            for (const auto& edge : pair.second) {
                if (pair.first == start) startFlag = true;
                else if (!startFlag) distances[pair.first] = -1;

                if (distances[pair.first] != -1 && startFlag) {
                    if (distances.find(edge.to) == distances.end() || distances[edge.to] > distances[pair.first] + edge.weight)
                        distances[edge.to] = distances[pair.first] + edge.weight;
                }
            }
            if (distances.find(end) != distances.end())
                minDistance = distances[end];
        }

        if (minDistance == INTMAX_MAX) return -1;
        return minDistance;
    }
};

#endif