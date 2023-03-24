// Number of Provinces - Leetcode
// Time Complexity = O(V)
// Space Complexity = O(V) + O(2E)

class Solution
{

public:
  void dfs(int node, vector<int> adj[], vector<int> &vis)
  {
    vis[node] = 1;
    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        // vis[node] = 1;
        dfs(it, adj, vis);
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int V = isConnected.size();
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
      for (int j = 0; j < V; j++)
      {
        if (isConnected[i][j] == 1 && i != j)
        {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    vector<int> vis(V, 0);
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
      if (!vis[i])
      {
        cnt++;
        dfs(i, adj, vis);
      }
    }

    return cnt;
  }
};

// BFS Approach

class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isConnected[i][j] == 1)
        {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int cnt = 0;
    vector<int> vis(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        cnt++;
      }
      q.push(i);
      while (!q.empty())
      {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
          if (!vis[it])
          {
            vis[it] = 1;
            q.push(it);
          }
        }
      }
    }
    return cnt;
  }
};
