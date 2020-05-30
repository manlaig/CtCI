#include <iostream>
#include <queue>
#include <set>

namespace BST
{
    struct Node
    {
        int val;
        Node *left, *right;
        Node(int v) : val(v), left(0), right(0) {}
    };

    void add(Node*& root, int val)
    {
        if(!root)
            root = new Node(val);
        else
            add(val > root->val ? root->right : root->left, val);
    }

    void print_in_order(Node* root)
    {
        if(!root)
            return;
        print_in_order(root->left);
        std::cout << root->val << " ";
        print_in_order(root->right);
    }

    // TODO: complete this function
    // I forgot how to PRINT by level, I'm currently traversing with BFS,
    // now I need to print them in right way
    void print_by_level(Node* root)
    {
        std::queue<Node*> q;
        q.push(root);
        
        while(q.size())
        {
            Node* top = q.front();
            q.pop();
            if(top->left)
                q.push(top->left);
            if(top->right)
                q.push(top->right);
            std::cout << top->val << " ";
        }
    }

    int get_height(Node* root)
    {
        if(!root)
            return 0;
        return std::max(get_height(root->left), get_height(root->right)) + 1;
    }
}
