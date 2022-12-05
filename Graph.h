#ifndef _GRATH_H_
#define _GRATH_H_
#include <iostream>
#include "Array.h"
#include "Queue.h"
#define MAX_INT 2147483627
#define MIN_INT -2147483628

class Graph {
public:
    Graph();
    Graph(int size);
    Graph(int size, int weight);
    Graph(Array<Array<int>>& graph);
    int get(int col, int row);
    int getSize();
    void setPath(int src, int dest, int w);
    void setUndirePath(int src, int dest, int w);
    void setSize(int size);
    bool hasCircle();
    int getMinDist(int src, int dest);
    // void dijkstra();
    // void floyd();
    // void prim();
    void dfs();
    void dfsHelp();
    void bfs(int src);
    Array<int>& operator[](int index);

public:
    Array<Array<int>> graph;
    int size;
};

Graph::Graph() {
    size = 10;
}

Graph::Graph(int size) {
    this->size = size;
}

Graph::Graph(int size, int weight) {
    this->size = size;
    Array<Array<int>> *g = new Array<Array<int>>(size);
    for (int i = 0; i < size; i++) {
        Array<int> *a = new Array<int>(size);
        for (int j = 0; j < size; j++) {
            a[j] = weight;
        }
        (*g)[i] = *a;
    }
    this->graph = *g;
}

int Graph::get(int row, int col) {
    return graph[row][col];
}

int Graph::getSize() {
    return size;
}

void Graph::setPath(int src, int dest, int w) {
    graph[src][dest] = w;
}

void Graph::setSize(int size) {
    this->size = size;
}

void Graph::bfs(int src) {
    int* book = new int[size];
    Queue<int> q;
    q.enqueue(src);
    int flag = 0;  // not a valid path
    for (int i = 0; i < size; i++) {
        int w = graph[src][i];
        if (w != flag)
            q.enqueue(w);
    }
    std::cout << src;
    q.dequeue();
    while (!q.isEmpty()) {
        int src = q.front();
        std::cout << " " << src;
        q.dequeue();
        for (int i = 0; i < size; i++) {
            int w = graph[src][i];
            if (w != flag)
                q.enqueue(w);
        }
    }
    std::cout << std::endl;
    delete[] book;
}

Array<int>& Graph::operator[](int index) {
    return graph[index];
}

#endif