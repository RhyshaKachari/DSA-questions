// Cheapest Flights Within K Stops - Leetcode

// Time Complexity - O(E)
// Space Complexity - O(E + V)

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // making the adjacency list
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // distance vector
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // making the queue
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
            {
                continue;
            }
            for (auto it : adj[node])
            {
                int edgenext = it.first;
                int edgeW = it.second;

                if (cost + edgeW < dist[edgenext] && stops <= k)
                {
                    dist[edgenext] = cost + edgeW;
                    q.push({stops + 1, {edgenext, dist[edgenext]}});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }
        return dist[dst];
    }
};