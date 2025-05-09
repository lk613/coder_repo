cmake_minimum_required(VERSION 3.5.0)
project(code_repo VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(
    leetcode/695_岛屿最大面积
    leetcode/76_最小覆盖子串
    leetcode/104_二叉树最大深度
    leetcode/200_岛屿数量
    leetcode/53_最大子数组和
    leetcode/94_二叉树的中序遍历
    leetcode/102_二叉树层序遍历
    leetcode/226_翻转二叉树
    leetcode/101_对称二叉树
    leetcode/206_反转链表
    leetcode/88_合并两个有序数组
    leetcode/26_删除数组中重复项
    leetcode/27_移除元素
    leetcode/169_多数元素
    leetcode/2_两数相加
    leetcode/21_合并两个有序链表
    leetcode/138_随机链表的复制
    leetcode/146_LRU缓存
    leetcode/912_排序数组
    leetcode/1_两数之和
)

add_executable(code_repo 
    main.cpp
    leetcode/695_岛屿最大面积/MaxAreaOfIsland.cpp
    leetcode/104_二叉树最大深度/MaxDepthOfBinaryTree.cpp
    leetcode/200_岛屿数量/NumOfIsland.cpp
    leetcode/53_最大子数组和/MaxSubArray.cpp
    leetcode/94_二叉树的中序遍历/InorderTraveral.cpp
    leetcode/102_二叉树层序遍历/LevelOrder.cpp
    leetcode/226_翻转二叉树/InvertTree.cpp
    leetcode/101_对称二叉树/Symmetric.cpp
    leetcode/206_反转链表/InverseLinklist.cpp
    leetcode/88_合并两个有序数组/MergeSortedArray.cpp
    leetcode/26_删除数组中重复项/RemoveDuplicates.cpp
    leetcode/27_移除元素/RemoveElements.cpp
    leetcode/169_多数元素/MajorityElement.cpp
    leetcode/2_两数相加/AddTwoNumbers.cpp
    leetcode/21_合并两个有序链表/MergeTwoLists.cpp
    leetcode/138_随机链表的复制/CopyRandomList.cpp
    leetcode/146_LRU缓存/LRUCache.cpp
    leetcode/912_排序数组/SortArray.cpp
    leetcode/1_两数之和/TwoSum.cpp
)

target_link_libraries(code_repo m)

include(CTest)
enable_testing()

