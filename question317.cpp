//Shortest path in Undirected Graph having unit distance - GFG

//Time Complexity :  O(N + E), where N is the number of nodes and E is edges
//Space Compleity : O(N + E)


class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        //converting edges into an adjacency list
        
        vector<int>adj[N];
       for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }
        
        //creating a dist vector
        vector<int>dis(N , 1e9);
        dis[src] = 0;
        queue<int>q ;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                if(dis[node]+1 < dis[it]){
                    dis[it] = dis[node]+1 ;
                    q.push(it) ;
                }
                
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(dis[i] == 1e9){
                dis[i] = -1 ;
            }
        }
        return dis ;
    }
};