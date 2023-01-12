// Kadane's Algorithm - GFG

//Approach 1 - Brute Force
    // Time Complexity = O(N^3)
    // Space Complexity = O(1)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                    mx = max(sum, mx);
                }
            }
        }
        return mx;
    }
};

//Approach 2 - Better Brute Force
    // Time Complexity = O(N^2)
    // Space Complexity = O(1)
    class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int mx = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum > mx)
                {
                    mx = sum;
                }
            }
        }
        return mx;
    }
};

//Approach 3 - Most Optimal Approach (Kadane's Algorithm)
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {
        int sum = 0;
        int mx = INT_MIN;
        for (int it = 0; it < n; it++)
        {
    sum += arr[it];
    mx = max(mx, sum);
    if (sum < 0)
    {
        sum = 0;
    }
        }
        return mx;
}
}
;