// Find the Smallest Divisor Given a Threshold - Leetcode

// Time Complexity = O(n log n)
// Space Complexity = O(1)

class Solution
{
public:
    int func(vector<int> &nums, int t, int m)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += ((it - 1) / m) + 1;
        }
        return sum;
    }
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        sort(nums.begin(), nums.end());
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int mid;
        int ans;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int sum = func(nums, threshold, mid);
            if (sum > threshold)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};