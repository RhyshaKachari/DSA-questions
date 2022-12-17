//Frequencies of Limited Range Array Elements - GFG
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution{
public:
void frequencyCount(vector<int> &arr , int N ,int P){
unordered_map<int , int> umap;
for(int i = 0; i < N ; i++){
umap[arr[i]]++;
}
vector<int> v;
for(int i = 1 ; i <=P ; i++){
int key = i;
if(umap.find(key)==umap.end()){
cout<<"0"<<" ";
}
else cout<<umap[key]<<" ";}
}
};