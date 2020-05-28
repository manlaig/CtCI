struct Node
{
    Node* next;
    int val;
    Node(int v) : val(v), next(0) {}
    Node(int v, Node* n) : next(n), val(v) {}
};

namespace LL
{
    void print(Node* head)
    {
        while(head)
        {
            std::cout << head->val << ' ';
            head = head->next;
        }
        std::cout << std::endl;
    }

    inline void addToHead(Node*& head, int val)
    {
        head = new Node(val, head);
    }

    // we can also have a wrapper class containing both head and tail
    void addToTail(Node*& head, int val)
    {
        Node** walk = &head;
        while(*walk)
            walk = &((*walk)->next);
        *walk = new Node(val);
    }

    void deleteFirstOccur(Node*& head, int val)
    {
        Node** walk = &head;
        while(*walk && (*walk)->val != val)
            walk = &((*walk)->next);

        // unfortunately, we can't avoid this edge case :(
        // the node we're trying to delete must be in the list
        if(*walk)
        {
            Node* temp = *walk;
            *walk = (*walk)->next;
            delete temp;
        }
    }

    void deleteNode(Node*& head, Node* target)
    {
        Node** walk = &head;
        while(*walk != target)
            walk = &((*walk)->next);
        if(*walk)
        {
            Node *temp = *walk;
            *walk = (*walk)->next;
            delete temp;
        }
    }
}