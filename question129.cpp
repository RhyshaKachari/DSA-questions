// Topological Sort - GFG
// Time Complexity = O(V+E)
// Space Complexity = O(V)

Approach 1 : DFS class Solution
{
private:
    void dfs(int node, int vis[], vector<int> adj[], stack<int> &s)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, s);
            }
        }
        s.push(node);
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, s);
            }
        }

        vector<int> ans;
        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
