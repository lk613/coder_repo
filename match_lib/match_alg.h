#ifndef MATCH_ALG
#define MATCH_ALG

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define TRACK_MAX_NUM 24
#define OBJECT_MAX_NUM 16
#define COST_SQUARE_MATRIX_NUM 24
typedef enum
{
    NORMAL = 0,
    MATURE_ZERO = 1,
    UNMATCH_ZERO = 2
}MATCH_ZERO_ENUM;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) > (b)) ? (b) : (a))

void HungarianMatch(int rows, int cols, float cost_matrix[TRACK_MAX_NUM][OBJECT_MAX_NUM], 
    float match_matrix[TRACK_MAX_NUM][OBJECT_MAX_NUM]);

void TestHungarianAlgorithm();

#endif