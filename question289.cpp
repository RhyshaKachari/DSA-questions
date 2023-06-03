// Search in Rotated Sorted Array II - Leetcode

// Time Complexity - O(log n)
// Space Complexity - O(1)

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;

            // if the element is present
            if (nums[mid] == target)
            {
                return true;
            }

            // for duplicates situation
            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }

            // if left array is sorted
            else if (nums[low] <= nums[mid])
            {
                if (target >= nums[low] && target < nums[mid])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

            // if right array is sorted
            else
            {
                if (target > nums[mid] && target <= nums[high])
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