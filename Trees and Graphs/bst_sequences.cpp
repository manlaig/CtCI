#include <iostream>
#include <set>
#include <vector>
#include "Tree.h"

void permute_helper(std::vector<std::vector<int>>* out, std::vector<int> arr, int start, int end)
{
    if(start >= end)
    {
        out->push_back(arr);
        return;
    }
    for(int i = start; i < end; i++)
    {
        std::swap(arr[start], arr[i]);
        permute_helper(out, arr, start+1, end);
    }
}

std::vector<std::vector<int>> permutations(std::vector<int> arr)
{
    std::vector<std::vector<int>> out;
    permute_helper(&out, arr, 0, arr.size());
    return out;
}

void get_level_helper(std::vector<int>* out, int depth, int curr, BST::Node* root)
{
    if(!root)
        return;
    if(curr == depth)
        out->push_back(root->val);
    else
    {
        get_level_helper(out, depth, curr+1, root->left);
        get_level_helper(out, depth, curr+1, root->right);
    }
}

// depth is 0-indexed
std::vector<int>* get_level(BST::Node* root, int depth)
{
    std::vector<int>* out = new std::vector<int>();
    get_level_helper(out, depth, 0, root);
    return out;
}

std::vector<int> add(std::vector<int>& arr1, std::vector<int>& arr2)
{
    std::vector<int> p(arr1.size() + arr2.size());
    for(int i : arr1)
        p.push_back(i);
    for(int i : arr2)
        p.push_back(i);
    return p;
}

std::vector<std::vector<int>>* fill(std::vector<std::vector<int>>* out, std::vector<std::vector<int>>* p, int start, int depth)
{
    if(start >= depth)
        return out;
    if(!out->size())
    {
        std::vector<std::vector<int>> *editted = new std::vector<std::vector<int>>();
        for(int j = 0; j < p[start].size(); j++)
        {
            editted->push_back((*p)[j]);
        }
        return fill(editted, p, start+1, depth);
    }
    
    std::vector<std::vector<int>> *editted = new std::vector<std::vector<int>>();
    for(int i = 0; i < out->size(); i++)
        for(int j = 0; j < p[start].size(); j++)
        {
            editted->push_back(add((*out)[i], (*p)[j]));
        }
    return fill(editted, p, start+1, depth);
}

int main()
{
    BST::Node* root = 0;
    BST::add(root, 10);
    BST::add(root, 5);
    BST::add(root, 15);
    BST::add(root, 1);
    BST::add(root, 7);
    BST::add(root, 13);
    BST::add(root, 18);

    std::vector<std::vector<int>>* out;
    int depth = BST::get_height(root) - 1;
    std::vector<std::vector<int>> p[depth];
    for(int i = 0; i < depth; i++)
    {
        std::vector<int>* temp = get_level(root, i);
        p[i] = permutations(*temp);
        fill(out, p, 0, depth);
    }
}
