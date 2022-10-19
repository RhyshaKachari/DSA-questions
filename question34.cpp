Maximum Subarray - Leetcode
Medium

Approach 1 : Kadane's Algorithm
Time Complexity = O(n)
Space Complexity = O(1)


class Solution{
public:
int maxSubArray(vector<int> &nums) {
int pos = 0;
for(int i = 0 ; i <nums.size() ; i++){
if(nums[i] >= 0){
pos = 1;
break;
}
}

if(pos == 0){
int max = INT_MIN ;
for(int i = 0 ; i < nums.size() ; i++){
if(nums[i] > max){
max = nums[i];}
}
return max;
}
    
    

int maxSum = 0;
int cursum = 0;
for(int i = 0 ; i < nums.size()  ; i ++ ){
cursum = cursum+nums[i] ;
if(cursum > maxSum){
maxSum = cursum;
}
if(cursum<0){
cursum  = 0;}
}
return maxSum ; 
}
};

Remarks : Forgot the case when the array consists of only negative integers 
