//Number of Ways to Arrive at Destination - Leetcode
//Expected Time Complexity: O(M * logN + N)
//Expected Space Complexity: O(M+N)


class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {

        // converting roads into adjacency list
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // distance and way vector
        vector<long long> dis(n, -1);
        vector<long long> way(n, 0);

        // priority queue
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        dis[0] = 0;
        way[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long dist = it.first;
            long long node = it.second;
            for (auto it : adj[node])
            {
                long long adjN = it.first;
                long long edgeW = it.second;

                if (dis[adjN] == -1)
                {
                    dis[adjN] = dist + edgeW;
                    pq.push({dis[adjN], adjN});
                    way[adjN] = way[node];
                }
                else if (dist + edgeW < dis[adjN])
                {
                    dis[adjN] = dist + edgeW;
                    pq.push({dis[adjN], adjN});
                    way[adjN] = way[node];
                }
                else if (dist + edgeW == dis[adjN])
                {
                    way[adjN] = ((way[adjN] % 1000000007 + way[node]) % 1000000007) % 1000000007;
                }
            }
        }
        return way[n - 1] % 1000000007;
    }
};