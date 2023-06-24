//Detect cycle in an undirected graph - GFG
//Time Complexity = O(V+E)
//Space Complexity = O(V)

//Aprroach  - Using BFS
class Solution
{
private:
    bool detect(int src, int vis[], vector<int> adj[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, vis, adj))
                {
                    return true;
                }
            }
        }
        return false;
    }
};


//Approach 2 : DFS
//Time Complexity  : O(V+2E) 
//Space Complexity : O(V) +O(V) recursive stack space

class Solution {
  private:
  bool dfs(int node , int parent , vector<int>adj[] , int vis[]){
      vis[node] = 1;
      for(auto it : adj[node]){
          if(!vis[it]){
              if(dfs(it , node, adj , vis) == true){
                  return true;
              }
          }
          else if(parent != it){
              return true ;
          }
      }
      return false;
  }
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
       int vis[V] = {0} ;
       for(int i =  0 ; i < V ; i++){
           if(!vis[i]){
                if(dfs(i , -1 , adj , vis) == true){
               return true ;
           }
           }
          
       }
       return false;
    }
};