 //Shortest Path in Binary Matrix - Leetcode
 //Time Complexity - O(m*n)
 //Space Complexity - O(m*n)


class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1)
        {
            return -1;
        }
        if (n == 1 && m == 1 && grid[0][0] == 0)
        {
            return 1;
        }
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, n - 1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 1;
        q.push({1, {0, 0}});
        while (!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int dr = -1; dr <= 1; dr++)
            {
                for (int dc = -1; dc <= 1; dc++)
                {
                    int nrow = row + dr;
                    int ncol = col + dc;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] != 1 && dis + 1 < dist[nrow][ncol])
                    {
                        if (nrow == destination.first && ncol == destination.second)
                        {
                            return dis + 1;
                        }
                        dist[nrow][ncol] = dis + 1;
                        q.push({dis + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};