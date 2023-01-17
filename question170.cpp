// Index of First 1 in a Binary Sorted Infinite Array - Aditya Verma
//Time Complexity =  O(log n)
//Space Complexity = O(1)

class Solution
{
public:
    int searchInfinite(vector<int> &nums)
    {
        int low = 0;
        int high = 1;
        while (arr[high] < 1)
        {
            low = high;
            high = 2 * high;
        }
        int res = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == 1)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};
