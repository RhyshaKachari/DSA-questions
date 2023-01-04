// Replace O's with X's - GFG
// Time Complexity = O(N*M)
// Space Complexity = O(N*M)

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> mat, int delrow[], int delcol[])
    {
        vis[row][col] = 1;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int delrow[] = {-1, 0, 0, 1};
        int delcol[] = {0, 1, -1, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && vis[0][j] == 0)
            {
                dfs(0, j, vis, mat, delrow, delcol);
            }

            if (mat[n - 1][j] == 'O' && vis[n - 1][j] == 0)
            {
                dfs(n - 1, j, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && vis[i][0] == 0)
            {
                dfs(i, 0, vis, mat, delrow, delcol);
            }

            if (mat[i][m - 1] == 'O' && vis[i][m - 1] == 0)
            {
                dfs(i, m - 1, vis, mat, delrow, delcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && vis[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};