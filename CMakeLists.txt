cmake_minimum_required(VERSION 3.5.0)
project(code_repo VERSION 0.1.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(
    sort_alg/BubbleSort
    sort_alg/QuickSort
    matrix_lib
    sto/link_list
    sto/array
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
    sto/array/two_sum.c
    sto/array/hash_table.c
    sto/array/three_sum_zero.c
)

target_link_libraries(code_repo m)

include(CTest)
enable_testing()

