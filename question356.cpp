//Longest Alternating Subarray - Leetcode
//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = -1;
        for(int i = 0 ; i < n ; i++){
            int flag = 1;
            for(int j = i+1 ; j <n  ; j++){
                if(nums[j]-nums[j-1] == flag){
                    flag = -1*flag ;
                    maxi = max(maxi , j-i+1 );
                }
                else{
                    break ;
                }
            }
        }
        return maxi ;
    }
};