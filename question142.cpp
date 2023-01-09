//Max Consecutive Ones - Leetcode
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
         int count = 0;
         int mx = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if (nums[i]==0)
            {   
                count = 0;
                continue;
            }
            count++;
            mx = max(mx , count);
        }
        return mx;
    }
};
