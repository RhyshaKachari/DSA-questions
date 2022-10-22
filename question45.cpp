Minimum Absolute Difference - LEETCODE
Easy
Time Complexity = O(n*logn) , Space Complexity = O(n)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
 sort(arr.begin() , arr.end()) ;
int n = arr.size();
int min =INT_MAX;
vector<vector<int>> ans ;
        
if(arr.size() == 0){return ans;}

for(int i = 0 ; i<n-1 ; i++){
if(min > abs(arr[i] -arr[i+1])){
min = abs(arr[i]-arr[i+1]);}
}


for(int i = 1 ; i<n ; i++){
if(abs(arr[i]-arr[i-1]) == min){
vector<int> v;
v.push_back(arr[i-1]);
v.push_back(arr[i]);
ans.push_back(v);
}
}

return ans;
  
    }
};