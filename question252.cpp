// Search in Rotated Sorted Array II - Leetcode
// Time Complexity = O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // element found
            if (nums[mid] == target)
            {
                return true;
            }
            // with duplicates we can have this contdition, just update left & right
            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
            // left array is sorted
            else if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target && target <= nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // right array is sorted
            else
            {
                if (nums[mid] <= target && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};
