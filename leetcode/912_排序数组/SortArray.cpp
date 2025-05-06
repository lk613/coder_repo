#include "SortArray.h"

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int pivot(std::vector<int> &array, int left, int right)
{
    int pivot_idx = 0;
    int pivot_data = array[left];
    int original_left = left;

    while (left < right)
    {
        while ((left < right) && (array[right] >= pivot_data))
        {
            right--;
        }
        while ((left < right) && (array[left] <= pivot_data))
        {
            left++;
        }

        swap(array[left], array[right]);
    }

    swap(array[original_left], array[left]);

    pivot_idx = left;
    return pivot_idx;
}

void quick_sort(std::vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int pivot_idx = pivot(array, start, end);
        quick_sort(array, start, pivot_idx - 1);
        quick_sort(array, pivot_idx + 1, end);
    }
}

// quick sort :  O(nlogn)
std::vector<int> sortArray(std::vector<int> &nums)
{
    int length = nums.size();

    quick_sort(nums, 0, length - 1);
    return nums;
}

void TestLeetcode912()
{
#if 1
    std::vector<int> nums = {5,1,1,2,0,0};
#else
    std::vector<int> nums = {5,2,3,1};
#endif
    std::cout << "nums数组为: " << std::endl;
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> sorted_array = sortArray(nums);
    std::cout << "排序后的数组为:  " << std::endl;
    for (int i = 0; i < sorted_array.size(); i++)
    {
        std::cout << sorted_array[i] << " ";
    }
    std::cout << std::endl;
}