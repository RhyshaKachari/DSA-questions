//Kth Largest Element in an Array - Leetcode
//Time Complexity = O(n log k)
//Space Complexity = O(k)

class Solution{
    public:
    int findKthLargest(vector<int> &nums ,int k){
        priority_queue<int , vector<int> , greater<int>> minH;
        for(int i = 0 ; i<nums.size() ; i++){
            minH.push(nums[i]);
            if(minH.size() > k){
                minH.pop();
            }
        }
       return minH.top(); 
    }
};