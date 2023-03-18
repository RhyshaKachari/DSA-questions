//Subset Sums - GFG

//Time Complexity = O(2^n)
//Space Complexity = O(2^n)

class Solution{
    public:
    void solve(int ind , int sum , int n ,vector<int>&ans, vector<int>&arr){
     if(ind == n){
        ans.push_back(sum);
        return;
     }   

     //take condition
     solve(ind+1 , sum+arr[ind] , n , ans, arr);
     //not take condition
     solve(ind+1 , sum , n , ans , arr);
    }
    vector<int> subsetSums(vector<int>arr ,int N){
        vector<int> ans;
        solve(0 , 0 , N , ans , arr);
        sort(ans.begin() , ans.end());
        return ans;
    }
};