#include <iostream>
#include <set>
#include "Graph.h"
#include "../Stacks and Queues/Queue.h"

// determine if there's a route from s to e (directed)
// BFS approach
bool route_betweek_nodes(Graph g, int s, int e)
{
    if(std::max(s, e) >= g.size || std::min(s, e) < 0)
        return false;
    std::set<int> visited;
    Queue q;
    q.add(s);
    while(q.size)
    {
        int node = q.remove();
        visited.insert(node);
        if(node == e)
            return true;
        Node* curr = g.arr[node];
        while(curr)
        {
            if(visited.find(curr->val) == visited.end())
                q.add(curr->val);
            curr = curr->next;
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addDirected(0, 1);
    g.addDirected(1, 2);
    g.addDirected(1, 0);
    g.addDirected(0, 3);

    g.print();
    std::cout << std::endl << route_betweek_nodes(g, 1, 3) << std::endl;
}
