// JUMP GAME II - LEETCODE
// Time Complexity = O(N*1000) or O(N^2)
// Space Complexity = O(N)

class Solution
{
private:
    int solve(int ind, int n, vector<int> &nums, vector<int> &dp)
    {
        int ans = 1e8;
        if (ind >= n - 1)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        for (int i = nums[ind]; i > 0; i--)
        {
            ans = min(ans, (1 + solve(ind + i, n, nums, dp)));
        }
        return dp[ind] = ans;
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(0, n, nums, dp);
    }
};

// Approach 2 : Greedy Approach
// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0;
        int end = 0;
        int farthest = 0;
        int jump = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + nums[i]);

            if (i == end)
            {
                jump++;
                end = farthest;
            }
        }
        return jump;
    }
};