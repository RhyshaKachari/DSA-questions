// Implementing Dijkstra Algorithm - GFG

// Approach 1 : Using Priority Queue
// Time Complexity - O(E log V)
// Space Complexity - O(E + V)

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int edgeNode = it[0];
                if (dist + edgeWeight < dis[edgeNode])
                {
                    dis[edgeNode] = dist + edgeWeight;
                    pq.push({dis[edgeNode], edgeNode});
                }
            }
        }
        return dis;
    }
};

// Approach 2 : Using sets
// Time Complexity - O(E log V)
// Space Complexity - O(E + V)

class Solution
{
public:
      vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(V, 1e9);
        set<pair<int, int>> st;
        dis[S] = 0;
        st.insert({0, S});
        while (!st.empty())
        {
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            st.erase(it);
            for (auto it : adj[node])
            {
                int wt = it[1];
                int ade = it[0];
                if (dist + wt < dis[ade])
                {
                    if (dis[ade] != 1e9)
                    {
                        st.erase({dis[ade], ade});
                    }
                    dis[ade] = dist + wt;
                    st.insert({dis[ade], ade});
                }
            }
        }
        return dis;
    }
};