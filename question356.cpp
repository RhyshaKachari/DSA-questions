//Longest Alternating Subarray - Leetcode
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution{
    public:
    int alternatingSubarray(vector<int>&nums){
        int n = nums.size() ;
        int cnt = 0;
        for(int m = 2 ; m <= n ; m++){
            if(nums[s-1] - nums[s-2] == pow(-1 , m)){
                cnt++ ;
            } 
            else{
                break ;
            }
        }
        if(cnt != 0){
            return cnt ;
        }
        return -1 ;
    }
}