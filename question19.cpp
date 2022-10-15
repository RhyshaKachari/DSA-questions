//Subsets - Leetcode
//Medium

//Approach 1 - Using bit manipulation
class Solution{
    public:
    vector<vector<int>> subsets(vector<int> &nums){
        int n =  nums.size();
        vector<vector<int>> subs;
        for(int i =0 ; i<(1<<n) ; i++){
            vector<int> arr;
            for (int j = 0; j <n; j++)
            {
              if(i&(1<<j)){
                arr.push_back(nums[j]);

              }
            }
         subs.push_back(arr);   
        }
        return subs;

    }  
};  
//Time Complexity = O(n);
//Space Complexity = O(n);

//Approach 2 - Through recursion

class Solution{
    public:
    void solve(vector<vector<int>> &v , vector<int> inp ,vector<int> &out){
if(inp.size() ==0){
v.push_back(out);
return;
}
vector<int> v1 = out;
vector<int>v2 = out;
v2.push_back(inp[0]);
inp.erase(inp.begin());
solve(v , inp , v1);
solve(v , inp , v2);
return;

}

    vector<vector<int>> subsets(vector<int> &nums){
     vector<vector<int>> v ;
     vector<int> out ;
     vector<int> inp = nums;
     solve(v ,inp , out);
    return v;
   }
};

//Time Complexity = O(n*2^n)
//Space Complexity = O(n)