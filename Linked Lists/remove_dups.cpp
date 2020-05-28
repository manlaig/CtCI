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
            // we advance walk in the else clause in a different way
            walk = &((*walk)->next);
        }
        else
        {
            // note that this way of deleting handles all edge cases
            Node* temp = *walk;
            *walk = (*walk)->next;
            delete temp;
        }
    }
}

void remove_dups_no_buffer(Node*& head)
{
    Node* out = nullptr;
    Node* curr = head;
    while(curr)
    {
        bool found = false;
        Node* trav = out;
        while(trav)
        {
            if(trav->val == curr->val)
            {
                found = true;
                break;
            }
            trav = trav->next;
        }
        if(!found)
            LL::addToTail(out, curr->val);
        curr = curr->next;
    }
    head = out;
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
    std::cout << "remove_dups: ";
    remove_dups(head);
    print(head);

    Node* head4 = nullptr;
    addToTail(head4, 10);
    addToTail(head4, 15);
    addToTail(head4, 10);
    addToTail(head4, 20);
    addToTail(head4, 20);
    addToTail(head4, 20);
    addToHead(head4, 11);
    addToHead(head4, 12);
    addToHead(head4, 12);
    addToHead(head4, 12);
    std::cout << "remove_dups_no_buffer: ";
    remove_dups(head4);
    print(head4);
    std::cout << std::endl;

    Node* head2 = nullptr;
    addToTail(head2, 20);
    addToTail(head2, 20);
    addToTail(head2, 20);
    std::cout << "before: ";
    print(head2);
    std::cout << "remove_dups: ";
    remove_dups(head2);
    print(head2);

    Node* head5 = nullptr;
    addToTail(head5, 20);
    addToTail(head5, 20);
    addToTail(head5, 20);
    std::cout << "remove_dups_no_buffer: ";
    remove_dups(head5);
    print(head5);
    std::cout << std::endl;

    Node* head3 = 0;
    std::cout << "before: ";
    print(head3);
    std::cout << "remove_dups: ";
    remove_dups(head3);
    print(head3);

    Node* head6 = 0;
    std::cout << "remove_dups_no_buffer: ";
    remove_dups(head6);
    print(head6);
}
