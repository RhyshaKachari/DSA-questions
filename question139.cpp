// JUMP GAME - LEETCODE
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
private:
    int solve(int ind, int n, vector<int> &nums, vector<int> &dp)
    {
        int ans = 1e8;
        if (ind >= n -1)
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