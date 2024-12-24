#include "quick_sort.h"

static void Swap(int *data_a, int *data_b);
static int SearchPivot(int *input_array, int left, int right, int ascend_flag);

static void Swap(int *data_a, int *data_b)
{
    int temp;
    temp = *data_a;
    *data_a = *data_b;
    *data_b = temp;
}

static int SearchPivot(int *input_array, int left, int right, int ascend_flag)
{
    int pivot;
    int pivot_idx;
    int ascend_param = (1 == ascend_flag) ? 1 : -1;

    pivot = left;
    while (left < right)
    {
        while ((left < right) && (ascend_param * input_array[right] > ascend_param * input_array[pivot]))
        {
            right--;
        }
        while ((left < right) && (ascend_param * input_array[left] <= ascend_param * input_array[pivot]))
        {
            left++;
        }
        Swap(&input_array[left], &input_array[right]);
    }

    Swap(&input_array[pivot], &input_array[left]);
    pivot_idx = left;
    
    return pivot_idx;
}

void QuickSort(int *sort_data, int start, int end, int ascend_flag)
{
    if (start < end)
    {
        int pivot = SearchPivot(sort_data, start, end, ascend_flag);
        QuickSort(sort_data, 0, pivot -1 , ascend_flag);
        QuickSort(sort_data, pivot + 1, end, ascend_flag);
    }
}