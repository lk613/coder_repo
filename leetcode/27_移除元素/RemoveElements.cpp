#include "RemoveElements.h"

// fast ponter and slow pointer method
int removeElement(vector<int>& nums, int val) {
    int length = nums.size();
    if (length <= 0)
    {
        return 0;
    }

    int fast = 0, slow = 0;

    while (fast < length)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}
