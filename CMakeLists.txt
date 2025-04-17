cmake_minimum_required(VERSION 3.5.0)
project(code_repo VERSION 0.1.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(
    sort_alg/BubbleSort
    sort_alg/QuickSort
    matrix_lib
    sto/link_list
    sto/array
    sto/stack
    sto/queue
    sto/binary_search
    leetcode/695_岛屿最大面积
    leetcode/76_最小覆盖子串
)

add_executable(code_repo 
    main.c
    sort_alg/BubbleSort/bubble_sort.c
    sort_alg/QuickSort/quick_sort.c
    matrix_lib/matrix.c
    sto/link_list/reverse_linklist.c
    sto/link_list/delete_inverse_kth.c
    sto/link_list/list_node.c
    sto/link_list/detect_cycle_linklist.c
    sto/link_list/first_common_node.c
    sto/link_list/add_linklist.c
    sto/array/two_sum.c
    sto/array/hash_table.c
    sto/array/three_sum_zero.c
    sto/stack/stack_struct.c
    sto/stack/suffix_expression.c
    sto/queue/queue_struct.c
    sto/queue/slide_window.c
    sto/binary_search/binary_search.c
    sto/binary_search/search_peek.c
    sto/binary_search/inverse_pairs.c
    leetcode/695_岛屿最大面积/MaxAreaOfIsland.c
)

target_link_libraries(code_repo m)

include(CTest)
enable_testing()

