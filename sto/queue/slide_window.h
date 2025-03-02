#ifndef SLIDE_WINDOW_H
#define SLIDE_WINDOW_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
// #include "queue_struct.h"

int* AverageWindow(int *array, int length, int win_size);

int* MaxWindow(int *array, int length, int win_size);

int* maxInWindows(int* num, int numLen, int size, int* returnSize);

#endif

