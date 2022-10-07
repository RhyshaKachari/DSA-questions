//Subsets - Leetcode
//Medium

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