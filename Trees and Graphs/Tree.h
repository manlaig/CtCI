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
        std::queue<std::pair<Node*, int> > q;
        q.push(std::make_pair(root, 1));
        int prev_depth = 0;

        while(q.size())
        {
            std::pair<Node*, int> top = q.front();
            q.pop();

            if(top.first->left)
                q.push(std::make_pair(top.first->left, top.second+1));
            if(top.first->right)
                q.push(std::make_pair(top.first->right, top.second+1));
            
            if(prev_depth != top.second)
            {
                prev_depth = top.second;
                std::cout << std::endl;
            }
            std::cout << top.first->val << " ";
        }
        std::cout << std::endl;
    }

    int get_height(Node* root)
    {
        return !root ? 0 : std::max(get_height(root->left), get_height(root->right)) + 1;
    }
}
