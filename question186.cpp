// Subarray Sum Equals K - Leetcode

// Time Complexity =  O(n^2)
// Space Complexity = O(1)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = nums[i];
            if (sum == k)
            {
                count++;
            }
            for (int j = i + 1; j < n; j++)
            {
                sum = sum + nums[j];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};