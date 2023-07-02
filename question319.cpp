// Shortest Path in Weighted undirected graph - GFG

// Time Complexity : O(M log N)
// Space Complexity : O(N)

class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {

        // making the adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // dis and parent vector
        vector<int> dis(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = i;
        }

        // priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[1] = 0;
        pq.push({0, 1});

        // dikstra's algorithm
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int edgeW = it.second;
                int edgeN = it.first;
                if (dist + edgeW < dis[edgeN])
                {
                    dis[edgeN] = dist + edgeW;
                    pq.push({dis[edgeN], edgeN});
                    parent[edgeN] = node;
                }
            }
        }

        // if nth node is unreachable
        if (dis[n] == 1e9)
        {
            return {-1};
        }

        // determining the path
        int node = n;
        vector<int> path;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};