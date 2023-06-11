// Minimum Path Sum -  Leetcode

// Approach 1 : Recursive Approach
// Time Complexity : O(2^M*N)
// Space Complexity : O(2^M*N) + O(m-1 + n-1)

// This will give TLE

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> grid)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        if (i < 0 || j < 0)
        {
            return 100000;
        }
        int up = grid[i][j] + f(i - 1, j, grid);
        int left = grid[i][j] + f(i, j - 1, grid);
        return min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return f(m - 1, n - 1, grid);
    }
};

// Approach 2 : Memoization
// Time Complexity : O(M*N)
// Space Complexity : O(M*N) + O(N-1 + N-1)

// This will also give TLE

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> grid, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }

        if (i < 0 || j < 0)
        {
            return 100000;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = grid[i][j] + f(i - 1, j, grid, dp);
        int left = grid[i][j] + f(i, j - 1, grid, dp);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, grid, dp);
    }
};

// Approach 3 : Tabulation
// Time Complexity - O(M*N)
// Space Complexity - O(N*N)

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else
                {
                    int up = 10000;
                    int left = 10000;
                    if (i > 0)
                    {
                        up = grid[i][j] + dp[i - 1][j];
                    }
                    if (j > 0)
                    {
                        left = grid[i][j] + dp[i][j - 1];
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Approach 4 : Space Optimisation
// Time Compelxity : O(M*N)
// Space Complexity : O(N)


class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = grid[0][0];
                }
                else
                {
                    int up = 10000;
                    int left = 10000;
                    if (i > 0)
                    {
                        up = grid[i][j] + prev[j];
                    }
                    if (j > 0)
                    {
                        left = grid[i][j] + cur[j - 1];
                    }

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};