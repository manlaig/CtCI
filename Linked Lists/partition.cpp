#include <iostream>
#include "Node.h"

// partition the Linked list around the value x
void partition(Node*& head, int x)
{
    Node *left = 0, *right = 0;

    while(head)
    {
        // save this pointer since we'll override it below
        Node* temp = head->next;
        if(head->val < x)
        {
            head->next = left;
            left = head;
        }
        else
        {
            head->next = right;
            right = head;
        }
        head = temp;
    }
    // connecting left and right together
    Node** l = &left;
    while(*l)
        l = &((*l)->next);
    *l = right;
    head = left;
}

int main()
{
    using namespace LL;
    Node* head = 0;
    addToTail(head, 1);
    addToTail(head, 5);
    addToTail(head, 4);
    addToTail(head, 3);
    addToTail(head, 2);
    addToTail(head, 6);
    print(head);
    partition(head, 3);
    print(head);
    std::cout << std::endl;

    Node* head2 = 0;
    addToTail(head2, 1);
    addToTail(head2, 5);
    addToTail(head2, 4);
    addToTail(head2, 3);
    addToTail(head2, 2);
    addToTail(head2, 6);
    print(head2);
    partition(head2, 10);
    print(head2);
}