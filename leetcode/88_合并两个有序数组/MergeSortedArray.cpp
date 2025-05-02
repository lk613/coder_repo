#include "MergeSortedArray.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int length = m + n;
    std::vector<int> vec(length);

    int i = 0, j = 0;
    int k = 0;

    while (i < m || j < n)
    {
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                vec[k] = nums1[i];
                i++;
                k++;
            }else
            {
                vec[k] = nums2[j];
                j++;
                k++;
            }
        }
    
        if (i < m)
        {
            vec[k] = nums1[i];
            i++;
            k++;
        }
    
        if (j < n)
        {
            vec[k] = nums2[j];
            j++;
            k++;
        }
    }

    for (int i = 0; i < length; i++)
    {
        nums1[i] = vec[i];
    }
}


void TestLeetcode88()
{
    std::vector<int> nums1 = {1,2,3,0,0,0};
    int m = 3;
    std::cout << "nums1 : " << std::endl;
    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

    std::vector<int> nums2 = {2,5,6};
    int n = 3;
    for (int i = 0; i < nums2.size(); i++)
    {
        std::cout << nums2[i] << " ";
    }
    std::cout << std::endl;

    merge(nums1, m, nums2, n);

    std::cout << "合并后, nums1为: " << std::endl;

    for (int i = 0; i < nums1.size(); i++)
    {
        std::cout << nums1[i] << " ";
    }
    std::cout << std::endl;

}