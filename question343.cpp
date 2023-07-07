// Minimum sum partition - GFG

// Approach 1 : Tabulation
// Time Complexity - O(N*|sum of array elements|)
// Space Complexity -  O(N*|sum of array elements|)

class Solution
{

public:
    int minDifference(int nums[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        if (nums[0] <= sum)
        {
            dp[0][nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target < sum + 1; target++)
            {
                bool nottake = dp[ind - 1][target];
                bool take = false;
                if (nums[ind] <= target)
                {
                    take = dp[ind - 1][target - nums[ind]];
                }
                dp[ind][target] = take | nottake;
            }
        }

        int mini = 1e9;
        for (int i = 0; i <= sum / 2; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int diff = abs(i - (sum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

// Approach 2 : Space Optimisation
// Time Complexity - O(N*|sum of array elements|)
// Space Complexity -  O(1)


class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int totSum = 0;

        for (int i = 0; i < n; i++)
        {
            totSum += arr[i];
        }

        vector<bool> prev(totSum + 1, false);

        prev[0] = true;

        if (arr[0] <= totSum)
            prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> cur(totSum + 1, false);
            cur[0] = true;
            for (int target = 1; target <= totSum; target++)
            {
                bool notTaken = prev[target];

                bool taken = false;
                if (arr[ind] <= target)
                    taken = prev[target - arr[ind]];

                cur[target] = notTaken || taken;
            }
            prev = cur;
        }

        int mini = 1e9;
        for (int i = 0; i <= totSum; i++)
        {
            if (prev[i] == true)
            {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};