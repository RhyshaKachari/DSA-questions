// House Robber 2 - Leetcode

// Time Complexity - O(N)
// Space Complexity - O(1)


class Solution
{
public:
    int solve(vector<int> temp)
    {
        int n = temp.size();
        int prev = temp[0];
        int prev2 = 0;
        for (int i = 0; i < n; i++)
        {
            int pick = temp[i];
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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }

        int ans1 = solve(temp1);
        int ans2 = solve(temp2);
        return max(ans1, ans2);
    }
};