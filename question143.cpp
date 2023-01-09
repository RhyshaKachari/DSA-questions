//Single Element in a Sorted Array - Leetcode
//Time Complexity : O(log N)
//Space Complexity : O(1)

class Solution{
    public:
    int singleNumber(vector<int> &nums){
        int low = 0;
        int high = nums.size() -2;
        while(low<=high){
            int mid = (low + high)>>1;
            if(nums[mid] == nums[mid^1]){
                low = mid +1;
            }
            else{
                high = mid-1;
            }
        }
        return nums[low];
    }
}