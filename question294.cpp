// House Robber - Leetcode

// Approach 1 :  Memoization
// Time Complexity - O(n)
// Space Complexity - O(n)+O(n)

class Solution
{
public:
    int f(int ind, vector<int> &dp, vector<int> &nums)
    {
        if (ind == 0)
        {
            return nums[ind];
        }
        if (ind < 1)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int pick = nums[ind] + f(ind - 2, dp, nums);
        int notpick = f(ind - 1, dp, nums);
        return dp[ind] = max(pick, notpick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, dp, nums);
    }
};

// Approach 2 : Tabulation

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i - 2 >= 0)
            {
                pick += dp[i - 2];
            }
            int notpick = dp[i - 1];

            dp[i] = max(pick, notpick);
        }
        return dp[n - 1];
    }
};

// Approach 3 : Space Optimisation

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i - 2 >= 0)
            {
                pick += prev2;
            }
            int notpick = prev;

            int curr = max(pick, notpick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};