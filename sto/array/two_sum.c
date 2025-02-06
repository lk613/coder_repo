#include "two_sum.h"

/**
 * @brief two pointer method to find two elements sum is target
 * 
 * @param arr 
 * @param len 
 * @param target 
 * @param ret : return two elements index
 * @return int 
 */
int TwoElemSum(int *arr, int len, int target, int *ret)
{
    int left;
    int right;
    ret[0] = -1;
    ret[1] = -1;

    if (arr == NULL || len <= 1)
    {
        return -1;
    }

    left = 0;
    right = len - 1;
    
    while (left < right)
    {
        if (arr[left] + arr[right] < target)
        {
            left++;
        }else if (arr[left] + arr[right] > target)
        {
            right--;
        }else
        {
            ret[0] = left;
            ret[1] = right;
            return 0;
        }
    }

    return -1;
}


/**
 * @brief two elements sum is target by hash table
 * 
 * @param arr 
 * @param len 
 * @param target 
 * @param ret 
 * @return int 
 */
int TwoElemSumByHashTable(int *arr, int len, int target, int *ret)
{
    int i;
    int value_t;
    int complement;
    HashTable hash_table;
    init(&hash_table);

    ret[0] = -1;
    ret[1] = -1;
    if (NULL == arr || len < 2)
    {
        return -1;
    }

    for (i = 0; i < len; i++)
    {
        value_t = arr[i];
        complement = target - value_t;

        int ret_find = search(&hash_table, complement);
        if (-1 != ret_find)
        {
            ret[0] = ret_find;
            ret[1] = i;
            return 0;
        }else
        {
            insert(&hash_table, value_t, i);
        }
    }
    return -1;
}

void PrintArr(int *arr, int len)
{
    if (arr == NULL || len <= 0)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return;
}

