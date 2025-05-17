#include "quick_sort_meijia.h"

static void PrintArray(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

static void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

#if 1
static int get_pivot(std::vector<int> &nums, int left, int right)
{
    int pivot_data = nums[left];
    int original_left = left;

    while (left < right)
    {
        while ((left < right) && (nums[right] >= pivot_data))
        {
            right--;
        }

        while ((left < right) && (nums[left] <= pivot_data))
        {
            left++;
        }

        swap(nums[left], nums[right]);
    }

    swap(nums[original_left], nums[left]);
    int pivot_idx = left;
    
    return pivot_idx;
}
#else
static int get_pivot(std::vector<int> &nums, int left, int right)
{
    int pivot_data = nums[left];
    int i = left;
    int j = right;
    
    while (i < j)
    {
        while ((i < j) && (nums[j] >= pivot_data))
        {
            j--;
        }

        while ((i < j) && (nums[i] <= pivot_data))
        {
            i++;
        }

        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    int pivot_idx = i;

    return pivot_idx;
}
#endif

void quick_sort_meijia(std::vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int pivot_index = get_pivot(array, start, end);
        quick_sort_meijia(array, start, pivot_index - 1);
        quick_sort_meijia(array, pivot_index + 1, end);
    }
}

void TestMeijiaQuickSort()
{
    std::vector<int> test_array = {10, 2, 5, 3, 1, 21};
    // std::vector<int> test_array = {5, 3, 3, 7, 3};
    std::cout << "before sort, array is : " << std::endl;
    PrintArray(test_array);

    int start_idx = 0;
    int end_idx = test_array.size() - 1;
    std::cout << "quicks sort ... " << std::endl;
    quick_sort_meijia(test_array, start_idx, end_idx);

    std::cout << "after sort, array is: " << std::endl;
    PrintArray(test_array);
}