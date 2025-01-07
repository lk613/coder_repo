cmake_minimum_required(VERSION 3.5.0)
project(code_repo VERSION 0.1.0 LANGUAGES C)

set(CMAKE_BUILD_TYPE "Debug")

include_directories(
    sort_alg/BubbleSort
    sort_alg/QuickSort
    matrix_lib
)

add_executable(code_repo 
    main.c
    sort_alg/BubbleSort/bubble_sort.c
    sort_alg/QuickSort/quick_sort.c
    matrix_lib/matrix.c
)

include(CTest)
enable_testing()

