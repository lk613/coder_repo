#ifndef Max_DEPTH_OF_BINARY_TREE_H
#define Max_DEPTH_OF_BINARY_TREE_H
#include <iostream>
#include <queue>
#include <vector>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
}TreeNode;

TreeNode *CreateBinaryTree(std::vector<int> &vec);

int MaxDepthOfBinaryTree(TreeNode *root);

#endif