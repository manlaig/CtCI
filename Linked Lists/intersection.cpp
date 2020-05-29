#include <iostream>
#include "Node.h"

// This is a kind of Brute Force way of doing
Node* intersection(Node* l1, Node* l2)
{
    // 0->1->2->3
    // 1->1->1->2->3

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
    std::cout << (inter ? inter->val : -1) << std::endl;
}