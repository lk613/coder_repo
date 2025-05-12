#include "MostWaterContainer.h"

// 双指针法
int maxArea(std::vector<int> &height)
{
    int length = height.size();
    if (length < 1)
    {
        return 0;
    }

    int left = 0;
    int right = length - 1;

    int max_area = 0;
    while (left < right)
    {
        int cur_area = min(height[left], height[right]) * (right - left);
        max_area = (cur_area > max_area) ? cur_area : max_area;
        if (height[left] < height[right])
        {
            left++;
        }else
        {
            right--;
        }
    }

    return max_area;
}