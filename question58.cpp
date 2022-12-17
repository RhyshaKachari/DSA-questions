//Non Repeating Element  - GFG
//Time Complexity = O(N)
//Space Complexiyt = O(N)

unordered_map<int , int> umap;
for(int i = 0 ; i < arr.size() ; i++){
int key = arr[i];
umap[key]++;
}
for(int i = 0 ; i <arr.size() ; i++){
if(umap[arr[i]] == 1){
return arr[i] ;
}
}
