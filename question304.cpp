// Unique Paths II - Leetcode

// Approach 1 : Recursive Approach
// Time Complexity : O(2^m*n)
// Space Complexity : O(m-1 + n-1)

// This approach will give TLE

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &obstacleGrid)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0)
        {
            return 0;
        }

        int up = f(i - 1, j, obstacleGrid);
        int right = f(i, j - 1, obstacleGrid);
        return up + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return f(m - 1, n - 1, obstacleGrid);
    }
};

// Approach 2 : Memoization

// Time Complexity : O(M*N)
// Space Complexity : O(M*N) + O(M-1 + N-1)

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = f(i - 1, j, obstacleGrid, dp);
        int right = f(i, j - 1, obstacleGrid, dp);
        return dp[i][j] = up + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(M*N)
// Space Complexity : O(M*N)

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }

                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        up = dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = dp[i][j - 1];
                    }
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Approach 4 : Space Optimisation
// Time Complexity : O(M*N)
// Space Complexity : O(N)

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> curr(n);
            for (int j = 0; j < n; j++)
            {
                if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
                {
                    curr[j] = 0;
                }
                else if (i == 0 && j == 0)
                {
                    curr[j] = 1;
                }

                else
                {
                    int up = 0;
                    int left = 0;
                    if (i > 0)
                    {
                        up = prev[j];
                    }
                    if (j > 0)
                    {
                        left = curr[j - 1];
                    }
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};