#include <iostream>
#include <vector>
#include "MaxAreaOfIsland.h"
#include "MaxDepthOfBinaryTree.h"
#include "NumOfIsland.h"
#include "MaxSubArray.h"
#include "MergeSortedArray.h"
#include "MajorityElement.h"
#include "AddTwoNumbers.h"
#include "SortArray.h"
#include "quick_sort_meijia.h"

#if 0
static void PrintVector(std::vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
#endif


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
    TestMeijiaQuickSort();

    // TestLeetcode912();

    // TestLeetCode_695();

    // TestLeetCode_104();
    
    // TestLeetcode200();

    // TestLeetcode_200();
    
    // TestLeetcode53();

    // TestLeetcode88();

    // TestLeetcode169();

    // TestLeetcode2();
    
    return 0;
}