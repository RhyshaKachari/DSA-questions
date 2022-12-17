//Key Pair - GFG
//Time Complexity = O(n)
//Space Complexity = O(n)


class Solution{
public:
bool hasArrayTwoCandidates(int arr[] , int n , int x){
unordered_map<int,int> umap;  
for(int i = 0 ; i < n ; i++){
umap[arr[i]]++;
}
for(auto it = umap.begin() ; it != umap.end() ; it++){
int key = x-it->first;
if(key == it->first){
if(it->second > 1){
return true ;}
}
else{
if(umap.find(key)!= umap.end()){
return true;}
}
}
return false;

}
};
