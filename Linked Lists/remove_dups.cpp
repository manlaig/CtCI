#include <iostream>
#include <set>
#include "Node.h"

void remove_dups(Node*& head)
{
    std::set<int> occurred;
    Node** walk = &head;

    while(*walk)
    {
        if(occurred.find((*walk)->val) == occurred.end())
        {
            occurred.insert((*walk)->val);
            walk = &((*walk)->next);
        }
        else
        {
            Node* temp = *walk;
            *walk = (*walk)->next;
            delete temp;
        }
    }
}

int main()
{
    using namespace LL;
    Node* head = nullptr;
    addToTail(head, 10);
    addToTail(head, 15);
    addToTail(head, 10);
    addToTail(head, 20);
    addToTail(head, 20);
    addToTail(head, 20);
    addToHead(head, 11);
    addToHead(head, 12);
    addToHead(head, 12);
    addToHead(head, 12);
    std::cout << "before: ";
    print(head);
    std::cout << "after: ";
    remove_dups(head);
    print(head);

    Node* head2 = nullptr;
    addToTail(head2, 20);
    addToTail(head2, 20);
    addToTail(head2, 20);
    std::cout << "before: ";
    print(head2);
    std::cout << "after: ";
    remove_dups(head2);
    print(head2);

    Node* head3 = 0;
    std::cout << "before: ";
    print(head3);
    std::cout << "after: ";
    remove_dups(head3);
    print(head3);
}
