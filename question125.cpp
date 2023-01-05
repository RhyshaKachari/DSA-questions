// Is Graph Bipartite? - Leetcode
// Time Complexity = O(V+E)
// Space Complexity = O(V)

Approach 1 : BFS Approach
class Solution
{
private:
    bool check(int start, vector<vector<int>> &graph, int V, int color[])
    {
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (check(i, graph, V, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};