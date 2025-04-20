#include "QuickSort.h"

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int pivot(std::vector<int> &array, int left, int right)
{
    int pivot_num = array[left];
    int i = left;
    int j = right;

    while (i < j)
    {
        while ((i < j) && (array[j] >= pivot_num))
        {
            j--;
        }

        while ((i < j) && (array[i] <= pivot_num))
        {
            i++;
        }

        swap(array[i], array[j]);
    }

    swap(array[left], array[i]);
    int pivot_idx = i;

    return pivot_idx;
}

void quickSort(std::vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int pivot_index = pivot(array, start, end);

        quickSort(array, start, pivot_index - 1);
        quickSort(array, pivot_index + 1, end);
    }
}

void PrintArray(std::vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (i < array.size() - 1)
        {
            std::cout << array[i] << " ";
        }else
        {
        std::cout << array[i] << std::endl;
        }
    }
}

void TestQuickSort()
{
    int array[10] = {12, 3, 7, 2, 2, 15, 9, 100, 3, 72};
    std::vector<int> vec(array, array + 10);

    std::cout << "当前数组为： " << std::endl;
    PrintArray(vec);

    quickSort(vec, 0, vec.size()-1);

    std::cout << "排序后的数组为： " << std::endl;
    PrintArray(vec);

}