// Bipartite Graph - GFG
//Time Complexity = O(V+E)
//Space Complexity = O(V)

Approach 2- DFS Approach

class Solution {
private:
bool dfs(int node ,int col , int color[] , int V ,vector<int>adj[]){
color[node] = col;
for(auto it: adj[node]){
if(color[it] == -1){
if(dfs(it , !col , color , V, adj)==false){return false;};
}
else if(color[it] == color[node]){return false;}
}
return true;
}

public:
bool isBipartite(int V, vector<int>adj[]){
int color[V];
for(int i = 0 ; i < V ;i++){
color[i] = -1 ;
}
//for traversing connected components
for(int i = 0 ; i < V ; i++){
if(color[i] == -1){
if(dfs(i , 0 ,color , V , adj) == false) {return false;} }
}
return true;
	}

};
