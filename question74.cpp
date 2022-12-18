//Check if Array is Sorted and Rotated - Leetcode
//Time Complexity = O(N)
//Space Complexity = O(1)

class Solution{
public:
bool check(vector<int >&nums){
int count = 0 ;
for(int i = 0 ; i <nums.size() ; i++ ){
if(nums[i] > nums[(i+1 )%nums.size()]){
count++ ;}
}
if(count >1){
return false;}
else return true;
}
};
