#ifndef IN_ORDER_TRAVERSAL
#define IN_ORDER_TRAVERSAL

#include <vector>
#include <iostream>

#ifdef RECURSIVE_ALGO
#define RECURSIVE_ALGO
#endif

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#ifdef RECURSIVE_ALGO
std::vector<int> inorderTraversal(TreeNode *root);
#endif

std::vector<int> inorderTraversal(TreeNode *root);

#endif