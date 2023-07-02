//Shortest Distance in a Binary Maze - GFG
//Time Complexity - O(n*m)
//Space Complexity - O(n*m)

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        if (source.first == destination.first &&
            source.second == destination.second)
            return 0;

        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
                {
                    if (nrow == destination.first && ncol == destination.second)
                    {
                        return dis + 1;
                    }
                    dist[nrow][ncol] = dis + 1;
                    q.push({dist[nrow][ncol], {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};
