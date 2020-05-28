#include <iostream>
#include "Node.h"

void delete_middle(Node*& head)
{
    int count = 0;
    Node* curr = head;
    while(curr)
    {
        count++;
        curr = curr->next;
    }
    curr = head;
    for(int i = 0; i < count/2-1; i++)
        curr = curr->next;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

int main()
{
    Node* head = 0;
    LL::addToTail(head, 1);
    LL::addToTail(head, 2);
    LL::addToTail(head, 5);
    LL::print(head);
    delete_middle(head);
    LL::print(head);
}