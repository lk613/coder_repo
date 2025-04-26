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
)

add_executable(code_repo 
    main.cpp
    leetcode/695_岛屿最大面积/MaxAreaOfIsland.cpp
    leetcode/104_二叉树最大深度/MaxDepthOfBinaryTree.cpp
    leetcode/200_岛屿数量/NumOfIsland.cpp
    leetcode/53_最大子数组和/MaxSubArray.cpp
)

target_link_libraries(code_repo m)

include(CTest)
enable_testing()

