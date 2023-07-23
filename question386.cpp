// Printing Longest Increasing Subsequence - GFG

// Time Complexity - O(n*n)
// Space Complexity - O(n)

class Solution
{
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        vector<int> dp(n, 1);
        vector<int> hsh(n, 1);
        for (int i = 0; i < n; i++)
        {
            hsh[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hsh[i] = prev;
                }
            }
        }

        int ans = -1;
        int lastIndex = -1;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] > ans)
            {
                ans = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hsh[lastIndex] != lastIndex)
        {
            lastIndex = hsh[lastIndex];
            temp.push_back(arr[lastIndex]);
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }
};
