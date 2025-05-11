#include "MoveZeros.h"

/**
 * 两次遍历
 * 创建两个指针 i 和 j，第一次遍历的时候指针 j 用来记录当前有多少 非0 元素。
 * 即遍历的时候每遇到一个 非0 元素就将其往数组左边挪，第一次遍历完后，j 指针的下标就指向了最后一个 非0 元素下标。
 * 第二次遍历的时候，起始位置就从 j 开始到结束，将剩下的这段区域内的元素全部置为 0。
 */
void moveZeroes(vector<int>& nums)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }

    while (j < nums.size())
    {
        nums[j++] = 0;
    }
}

/** 一次循环
 * 使用两个指针 i 和 j，只要 nums[i]!=0，我们就交换 nums[i] 和 nums[j]
 */
#if 0
void moveZeroes(vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i++] = temp;
        }
    }
}
#endif

// void moveZeroes(vector<int>& nums) {
//     int slow = 0;
//     int fast = 0;
//     int length = nums.size();

//     for (int i = 0; i < length; i++)
//     {
//         if (0 == nums[i])
//         {
//             slow = i;
//             fast = i + 1;
//             if (fast < length)
//             {
//                 while ((fast < length - 1) && (0 == nums[fast]))
//                 {
//                     fast++;
//                 }
//                 nums[slow] = nums[fast];
//                 nums[fast] = 0;
//             }
//         }else
//         {
//             slow++;
//         }
//     }
// }
