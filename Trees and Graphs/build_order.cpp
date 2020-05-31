#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include "Graph.h"
#include "../Linked Lists/Node.h"
#include "../Stacks and Queues/Queue.h"
#define p(a, b) std::make_pair(a, b)

std::stack<char> build_order(std::vector<char> projects, std::vector<std::pair<char, char> > dependencies)
{
    Graph g(projects.size());
    Graph g2(projects.size());
    std::set<char> visited, process_first;
    std::stack<char> out;

    // compile with -std=c++11 flag
    for(std::pair<char, char> d : dependencies)
    {
        // (a,b) = b is dependent on a
        // adding an edge from b to a
        // we can later traverse and see what each project's dependencies are
        g.addDirected(d.first - 97, d.second - 97);
        g2.addDirected(d.second - 97, d.first - 97);
    }

    for(int i = 0; i < g.size; i++)
    {
        std::cout << i << ": ";
        LL::print(g.arr[i]);
        if(!g.arr[i])
            process_first.insert((char) (i + 97));
    }

    Queue q;
    for(auto it = process_first.begin(); it != process_first.end(); it++)
    {
        q.add(*it - 97);
        out.push(*it);
        while(q.size)
        {
            int temp = q.remove();
            Node* curr = g2.arr[temp];
            while(curr)
            {
                if(visited.find(((char) curr->val + 97)) == visited.end())
                {
                    out.push(((char) curr->val + 97));
                    q.add(curr->val);
                    visited.insert(((char) curr->val + 97));
                }
                curr = curr->next;
            }
        }
    }
    return out;
}

int main()
{
    using namespace std;
    {
        vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
        vector<pair<char, char> > dependencies = {p('a', 'd'), p('f', 'b'), p('b', 'd'), p('f', 'a'), p('d', 'c'), p('e', 'f')};

        std::stack<char> q = build_order(projects, dependencies);
        while(!q.empty())
        {
            std::cout << q.top() << " ";
            q.pop();
        }
    }

    {
        vector<char> projects = {'a', 'b', 'c', 'd'};
        vector<pair<char, char> > dependencies = {p('b', 'a'), p('c', 'a'), p('c', 'b'), p('d', 'c')};

        std::stack<char> q = build_order(projects, dependencies);
        while(!q.empty())
        {
            std::cout << q.top() << " ";
            q.pop();
        }
    }
}