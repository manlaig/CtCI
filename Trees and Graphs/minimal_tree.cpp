#include <iostream>
#include "Tree.h"

// from and to are the array bounds
void helper(BST::Node*& root, int* arr, int from, int to)
{
    if(from >= to)
        return;
    int mid = (from + to) / 2;
    BST::add(root, arr[mid]);
    helper(root->left, arr, from, mid);
    helper(root->right, arr, mid+1, to);
}

BST::Node* minimal_tree(int* arr, int size)
{
    BST::Node* root = 0;
    helper(root, arr, 0, size);
    return root;
}

int main()
{
    int arr[3] = {1,2,3};
    BST::Node* out = minimal_tree(arr, 3);
    std::cout << out->val << std::endl;
    std::cout << out->left->val << " " << out->right->val<< std::endl;
    BST::print_in_order(out);
    std::cout << std::endl << "Height: " << BST::get_height(out) << std::endl;

    int arr2[6] = {1,2,3,4,5,6};
    BST::Node* out2 = minimal_tree(arr2, 6);
    std::cout << std::endl << out2->val << std::endl;
    std::cout << out2->left->val << " " << out2->right->val<< std::endl;
    BST::print_in_order(out2);
    std::cout << std::endl << "Height: " << BST::get_height(out2) << std::endl;
}