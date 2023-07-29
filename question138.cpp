// Jump Game - Leetcode

// Approach 1 : Memoization
// Time Complexity = O(N*max(nu))
// Space Complexity = O(N) + O(N)(recursive stack space)

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

// Approach 2 : Greedy Approach
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return true;
        }
        int mx = 0;
        for (int index = 0; index < n && mx >= index; index++)
        {
            if (mx < index + nums[index])
            {
                mx = index + nums[index];
            }
            if (mx >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};