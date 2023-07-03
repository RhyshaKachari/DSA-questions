//Subarray Product Less Than K - Leetcode
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = 1 ;
        int cnt = 0 ;
        int s = 0;
        int e = 0;
        while(e < nums.size()){
            p *= nums[e];
            while(p>= k && s < nums.size()){
                p = p/nums[s] ;
                s++;
            }
            if(p<k){
             cnt += e-s+1 ;
               
            }
            e++;
        }
        return cnt ;
    }
};