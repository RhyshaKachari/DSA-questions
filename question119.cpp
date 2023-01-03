// Rotting Oranges - Leetcode
// Time Complexity = O(N*M)
// Space Complexity = O(N*M)

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        int cntFresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                {
                    cntFresh++;
                }
            }
        }
        int tm = 0;
        int cnt = 0;
        int delRow[] = {-1, 0, 0, 1};
        int delCol[] = {0, -1, 1, 0};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] != 0)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh)
        {
            return -1;
        }
        return tm;
    }
};
