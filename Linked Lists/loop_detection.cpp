#include <iostream>
#include "Node.h"

Node* loop_detection(Node* head)
{
    Node* curr = head;
    while(curr)
        if(curr->next == head)
            return curr;
        else
            curr = curr->next;
    return nullptr;
}

int main()
{
    Node* head = 0;
    LL::addToTail(head, 1);
    LL::addToTail(head, 2);
    LL::addToTail(head, 3);
    head->next->next->next = head;
    // should return 3
    Node* out = loop_detection(head);
    std::cout << (out ? out->val : NULL) << std::endl;

    Node* head2 = 0;
    LL::addToTail(head2, 1);
    head2->next = head2;
    // should return 1
    Node* out2 = loop_detection(head2);
    std::cout << (out2 ? out2->val : NULL) << std::endl;

    Node* out3 = loop_detection(0);
    std::cout << (out3 ? out3->val : -1) << std::endl;
}