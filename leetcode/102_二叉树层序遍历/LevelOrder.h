#ifndef LEVEL_ORDER_BINRAY_TREE
#define LEVEL_ORDER_BINRAY_TREE

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root);

#endif