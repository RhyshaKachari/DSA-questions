//Shortest path in Directed Acyclic Graph - GFG


//Time Complexity -O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M).

//Space Complexity - O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .



class Solution
{
private:
    void toposort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            int v = it.first;
            if (!vis[v])
            {
                toposort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        // first we will create the adjacency list
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // now we do topo sort
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                toposort(i, adj, vis, st);
            }
        }

        vector<int> dis(N, 1e9);
        dis[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                if (dis[node] + wt < dis[v])
                {
                    dis[v] = dis[node] + wt;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (dis[i] == 1e9)
            {
                dis[i] = -1;
            }
        }
        return dis;
    }
};