//Jump Game - Leetcode

//Approach 1 : Memoization
//Time Complexity = O(N)
//Space Complexity = O(N) + O(N)(recursive stack space)


class Solution
{
private:
    bool solve(int ind, int n, vector<int> &nums, vector<int> &dp)
    {
        if (ind == n - 1)
        {
            return true;
        }
        if (ind >= n)
        {
            return false;
        }
        if (!dp[ind])
        {
            return dp[ind];
        }
        for (int i = 1; i <= nums[ind]; i++)
        {
            if (solve(ind + i, n, nums, dp))
            {
                return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }

public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, n, nums, dp);
    }
};
