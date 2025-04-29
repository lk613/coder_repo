#include <iostream>
#include <vector>
#include "MaxAreaOfIsland.h"
#include "MaxDepthOfBinaryTree.h"
#include "NumOfIsland.h"
#include "MaxSubArray.h"

static void PrintVector(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

static void TestLeetCode_695()
{
    #if 1
    // [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
    // 第一次提交未通过的测试用例，记得重复入队列的元素，导致重复计数
    std::vector<std::vector<int>> grid = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,0,1,1},
        {0,0,0,1,1}
    };

#else
    std::vector<std::vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
#endif
    int maxArea = maxAreaOfIslandByBfs(grid);
    std::cout << "Max area of island: " << maxArea << std::endl;
}

static void TestLeetCode_104()
{
    std::vector<int> vec = {3,9,20,-1,-1,15,7};
    std::cout << "Vectort is: " << std::endl;
    PrintVector(vec);
    TreeNode *root = CreateBinaryTree(vec);
    int maxDepth = MaxDepthOfBinaryTree(root);
    std::cout << "Max depth of binary tree: " << maxDepth << std::endl;
}


int main()
{
    // TestLeetCode_104();
    
    // TestLeetcode200();

    TestLeetcode_200();
    
    // TestLeetcode53();
    return 0;
}