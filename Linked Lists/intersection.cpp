#include <iostream>
#include <set>
#include "Node.h"

// This is a kind of Brute Force way of doing
Node* intersection(Node* l1, Node* l2)
{
    while(l1)
    {
        Node* temp = l2;
        while(temp)
        {
            if(l1 == temp)
                return temp;
            temp = temp->next;
        }
        l1 = l1->next;
    }
    return nullptr;
}

Node* fast_intersection(Node* l1, Node* l2)
{
    std::set<Node*> visited;
    while(l1)
    {
        visited.insert(l1);
        l1 = l1->next;
    }
    while(l2)
    {
        if(visited.find(l2) != visited.end())
            return l2;
        l2 = l2->next;
    }
    return nullptr;
}

int main()
{
    Node *l1 = 0, *l2 = 0;

    LL::addToTail(l1, 1);
    LL::addToTail(l1, 2);
    LL::addToTail(l1, 3);
    LL::addToTail(l2, 10);
    LL::addToTail(l2, 11);
    l2->next->next = l1->next;
    LL::print(l1);
    LL::print(l2);

    Node* inter = intersection(l1, l2);
    std::cout << "Brute Force: " << (inter ? inter->val : -1) << std::endl;
    Node* fast = fast_intersection(l1, l2);
    std::cout << "Fast Intersection: " << (fast ? fast->val : -1) << std::endl;
}