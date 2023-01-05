// Eventual Safe States - GFG
// Time Complexity = O(V+E)
// Space Complexity = O(V)

class Solution
{
private:
    bool dfsCheck(int node, int vis[], int pathVis[], int check[], vector<int> adj[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, vis, pathVis, check, adj) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safe;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, vis, pathVis, check, adj);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                safe.push_back(i);
            }
        }
        return safe;
    }
};
