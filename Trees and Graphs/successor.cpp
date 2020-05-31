#include <iostream>
#include "Tree.h"

// This was a pretty challenging problem for me

struct Node_Successor : public BST::Node
{
    BST::Node *parent; 
    Node_Successor(int v, BST::Node* p) : Node(v), parent(p) {}
};

void add_successor(BST::Node*& root, int val, BST::Node* parent = 0)
{
    if(!root)
        root = new Node_Successor(val, parent);
    else
        add_successor(val > root->val ? root->right : root->left, val, root);
}

BST::Node* successor(BST::Node* target)
{
    Node_Successor* node = dynamic_cast<Node_Successor*>(target);
    if(!node)
        return 0;
    if(node->right)
    {
        BST::Node* temp = node->right;
        while(temp->left)
            temp = temp->left;
        return temp;
    }
    while(node && node->parent && node->parent->val < node->val)
    {
        node = dynamic_cast<Node_Successor*>(node->parent);
    }
    return node->parent;
}

int main()
{
    BST::Node* root = 0;
    /*
                        5
                3               7
        1           4       6
            2
    */
    add_successor(root, 5);
    add_successor(root, 3);
    add_successor(root, 4);
    add_successor(root, 1);
    add_successor(root, 7);
    add_successor(root, 2);
    add_successor(root, 6);

    BST::print_in_order(root);
    {
        BST::Node* out = successor(root->left->left);
        std::cout << std::endl << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root->left->left->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root->left);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root->left->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root->right->left);
        std::cout << (out ? out->val : -1) << std::endl;
    }
    {
        BST::Node* out = successor(root->right);
        std::cout << (out ? out->val : -1) << std::endl;
    }
}