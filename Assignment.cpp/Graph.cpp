// Name : Virang Raje 
// Roll No. : 34
// Enrollment No. : ADT23SOCB1320

#include <iostream>
using namespace std;

#define MAX 10

class Graph {
private:
    int g[MAX][MAX];
    int noofedges, noofvertex;

public:
    Graph();
    void CreateGraph();
    void PrintGraph();
};

Graph::Graph() {
    cout << "Enter no. of vertices: ";
    cin >> noofvertex;
    cout << "Enter no. of edges: ";
    cin >> noofedges;

    for (int i = 0; i < noofvertex; i++) {
        for (int j = 0; j < noofvertex; j++) {
            g[i][j] = 0;
        }
    }
}

void Graph::CreateGraph() {
    int v1, v2;
    for (int i = 0; i < noofedges; i++) {
        cout << "Enter starting vertex and ending vertex (0 to " << noofvertex - 1 << "): ";
        cin >> v1 >> v2;
    }
}

void Graph::PrintGraph() {
    cout << "Adjacency Matrix of the given Graph is:" << endl;
    for (int i = 0; i < noofvertex; i++) {
        for (int j = 0; j < noofvertex; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g;
    g.CreateGraph();
    g.PrintGraph();
    return 0;
}