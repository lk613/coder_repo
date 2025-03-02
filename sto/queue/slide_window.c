#include "slide_window.h"


int* AverageWindow(int *array, int length, int win_size)
{

}

/**
 * @brief Get slide window max number
 * 
 * @param array 
 * @param length 
 * @param win_size 
 * @return int* 
 */
int* MaxWindow(int *array, int length, int win_size)
{
    int max_arr_num = length - win_size + 1;
    int ret[] = {0};

    int temp_window_size = 0;
    int ret_cnt = 0;
    bool window_full_flag = false;
    int max_cur = INT_MIN;
    int snd_max_cur = INT_MIN + 1;
    for (int i = 0; i < length; i++)
    {
        if (max_cur != array[i])
        {
            max_cur = (max_cur > array[i]) ? max_cur : array[i];
            if (max_cur != array[i])
            {
                snd_max_cur = (snd_max_cur > array[i]) ? snd_max_cur : array[i];
            }
        }

        if (false == window_full_flag)
        {
            temp_window_size++;
            if (temp_window_size == win_size)
            {
                window_full_flag = true;
            }
            continue;
        }
        
        int queue_front_idx = i - win_size;

        if (ret_cnt < max_arr_num)
        {
            ret[ret_cnt++] = (array[queue_front_idx] == max_cur) ? snd_max_cur : max_cur;
        }
    }

    return ret;
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param num int整型一维数组 
 * @param numLen int num数组长度
 * @param size int整型 
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */
int* maxInWindows(int* num, int numLen, int size, int* returnSize ) {
    // write code here
    int max_arr_num = numLen - size + 1;
    int *ret = (int *)malloc(max_arr_num * sizeof(int));
    if (NULL == ret)
    {
        *returnSize = 0;
        return NULL;
    }
    // int ret[] = {0 * max_arr_num};

    int temp_window_size = 0;
    int ret_cnt = 0;
    bool window_full_flag = false;
    int max_cur = INT_MIN;
    int snd_max_cur = INT_MIN + 1;
    for (int i = 0; i < numLen; i++)
    {
        if (max_cur != num[i])
        {
            if (max_cur > num[i])
            {
                snd_max_cur = (snd_max_cur > num[i]) ? snd_max_cur : num[i];
            }else
            {
                snd_max_cur = max_cur;
                max_cur = num[i];
            }
        }

        if (false == window_full_flag)
        {
            temp_window_size++;
            if (temp_window_size == size)
            {
                window_full_flag = true;
            }
            continue;
        }
        
        int queue_front_idx = i - size;

        if (ret_cnt < max_arr_num)
        {
            ret[ret_cnt++] = (num[queue_front_idx] == max_cur) ? snd_max_cur : max_cur;
        }
    }

    *returnSize = max_arr_num;
    return ret;
}

