#include <iostream>
#include "Tree.h"

bool check_balanced(BST::Node* root)
{
    if(!root)
        return true;
    int diff = std::abs(BST::get_height(root->left) - BST::get_height(root->right));
    if(diff <= 1 && check_balanced(root->left) && check_balanced(root->right))
        return true;
    return false;
}

int main()
{
    BST::Node* root = 0;
    /*
            5
        3       7    
    */
    BST::add(root, 5);
    BST::add(root, 3);
    BST::add(root, 7);
    std::cout << check_balanced(root) << std::endl; 
    /*
            5
        3       7    
                    9
                        11
    */
    BST::add(root, 9);
    BST::add(root, 11);
    std::cout << check_balanced(root) << std::endl; 
    /*
            5
        3       7    
    1       6        9
                        11
    */
    BST::add(root, 1);
    BST::add(root, 6);
    std::cout << check_balanced(root) << std::endl; 
    

}