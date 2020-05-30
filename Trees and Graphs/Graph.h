#include <iostream>
#include "../Linked Lists/Node.h"

// implementation of graph using an adjacency list
class Graph
{
    // array of node pointers
    Node* *arr;
    int size;
public:
    Graph(int vertices);
    ~Graph();
    void addDirected(int from, int to);
    void addUndirected(int from, int to);
    void print();
};

Graph::Graph(int vertices) : arr(new Node*[vertices]), size(vertices)
{
    for(int i = 0; i < vertices; i++)
        arr[i] = 0;
}

Graph::~Graph()
{
    for(int i = 0; i < size; i++)
    {
        while(arr[i])
        {
            Node* temp = arr[i]->next;
            delete arr[i];
            arr[i] = temp;
        }
    }
}

// doesn't check if the edge already exists
void Graph::addDirected(int from, int to)
{
    LL::addToTail(arr[from], to);
}

// doesn't check if the edge already exists
void Graph::addUndirected(int from, int to)
{
    LL::addToTail(arr[from], to);
    LL::addToTail(arr[to], from);
}

void Graph::print()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << i << ": ";
        LL::print(arr[i]);
    }
}