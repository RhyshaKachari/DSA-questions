//Print adjacency list - GFG
//Time Complexity = O(V+E)
//Space Complexity = O(V+E)

class Solution{
public:
vector<vector<int>> printGraph(int V , vector<int> adj[]){
vector<vector<int>> print(V);
for(int i =0 ; i < V; i++){
print[i].push_back(i);
for(int j = 0 ; j < adj[i].size() ; j++){
print[i].push_back(adj[i][j]);
}
}
return print;
}
};
