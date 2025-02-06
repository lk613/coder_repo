#ifndef TWO_SUM_H
#define TWO_SUM_H
#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

extern int TwoElemSum(int *arr, int len, int target, int *ret);

extern int TwoElemSumByHashTable(int *arr, int len, int target, int *ret);

extern void PrintArr(int *arr, int len);

#endif // TWO_SUM_H