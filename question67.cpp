//Relative Sort Array - Leetcode
//Time Complexity = O(nlog(n));
//Space Complexity = O(n)

class Solution {
public:
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
map<int , int> mp ;
for(int i =0 ; i < arr1.size() ; i++){
mp[arr1[i]]++;
}
vector<int> ans;
for(int i =0; i < arr2.size() ; i++){
int count = mp[arr2[i]];
vector<int> v(count , arr2[i]);
ans.insert(ans.end() , v.begin() , v.end());
mp[arr2[i]] = 0;
}
for(auto it  = mp.begin() ; it!= mp.end() ; it++){
if(it->second != 0){
vector<int> b(it->second , it->first);
ans.insert(ans.end() , b.begin() , b.end());
it->second = 0;

}
}return ans;

    }
};