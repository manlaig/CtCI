#include <iostream>
#include "Node.h"

int kth_to_last(Node*& head, int k)
{
    if(k < 0)
        return -1;

    Node* curr = head, *kth = head;
    for(int i = 0; i <= k; i++)
    {
        if(!curr)
            return -1;
        curr = curr->next;
    }

    while(curr)
    {
        kth = kth->next;
        curr = curr->next;
    }
    return kth->val;
}

int main()
{
    using namespace LL;
    Node* head = 0;
    addToTail(head, 1);
    addToTail(head, 2);
    addToTail(head, 3);
    addToTail(head, 4);
    std::cout << kth_to_last(head, -1) << std::endl;
    std::cout << kth_to_last(head, 0) << std::endl;
    std::cout << kth_to_last(head, 1) << std::endl;
    std::cout << kth_to_last(head, 2) << std::endl;
    std::cout << kth_to_last(head, 3) << std::endl;
    std::cout << kth_to_last(head, 4) << std::endl;

    Node* head2 = 0;
    std::cout << kth_to_last(head2, 0) << std::endl;
    std::cout << kth_to_last(head2, 1) << std::endl;

    Node* head3 = 0;
    addToTail(head3, 10);
    std::cout << kth_to_last(head3, -1) << std::endl;
    std::cout << kth_to_last(head3, 0) << std::endl;
    std::cout << kth_to_last(head3, 1) << std::endl;
}