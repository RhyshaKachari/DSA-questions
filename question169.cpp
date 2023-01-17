// Search in an Infinite Sorted Array - Leetcode
// Time Complexity = O(log N)
// Space Complexity = O(1)

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = 1;
        while (key > nums[high])
        {
            low = high;
            high = high * 2;
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
};
