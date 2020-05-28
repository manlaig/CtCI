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
}