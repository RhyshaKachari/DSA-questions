// Introduction to DP - GFG
// Time Complexity - O(N)
// Space Complexity - O(N)

long long int m = 1e9 + 7;
long long int dp[100001];
class Solution
{

    long long int memoise(int n, vector<long long int> &dp)
    {
        if (n <= 1)
        {
            return n;
        };
        if (dp[n] != 0)
        {
            return dp[n] % m;
        }
        return dp[n] = (memoise(n - 1, dp) + memoise(n - 2, dp)) % m;
    }

public:
    long long int topDown(int n)
    {
        vector<long long int> dp(n + 1, 0);
        long long int ans = memoise(n, dp);
        return ans;
    }

    long long int bottomUp(int n)
    {
        long long int prev = 1;
        long long int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            long long int curr = (prev + prev2) % m;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};