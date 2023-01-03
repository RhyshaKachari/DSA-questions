//Number of Islands - Leetcode (Different)
//Time Complexity = O(N*M)
//Space Of Complexity = O(N*M)

class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            int d[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (int k = 0; k < 4; k++)
            {

                int nrow = r + d[k][0];
                int ncol = c + d[k][1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !(vis[nrow][ncol]))
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if ((!vis[row][col]) && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};