// Maximum Average Subarray I  - Leetcode

// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;
        double mx = INT_MIN;
        double sum = 0.00000;
        int n = nums.size();
        while (j < n)
        {
            sum += nums[j];
            if (j - i + 1 < k)
            {
                j++;
            }
            else if (j - i + 1 == k)
            {
                mx = max(mx, sum);
                sum = sum - nums[i];
                i++;
                j++;
            }
        }
        return mx / k;
    }
};