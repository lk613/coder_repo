#ifndef SYMMETRIC_BINARY_TREE
#define SYMMETRIC_BINARY_TREE

#include <iostream>

#ifndef RECURSIVE_ALGO
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

bool isSymmetric(TreeNode* root);

#endif