 Find Minimum in Rotated Sorted Array - Leetcode
Time Complexity  = O(n) , Space Complexity = O(1)

Approach 1:
class Solution {
public:
    int findMin(vector<int>& nums) {
int start = 0;
int end = nums.size() -1;
while(start< end){
if(nums[start] < nums[end]){
return nums[start];}
int mid = start + (end- start)/2;
if(nums[mid] >= nums[start]){
start = mid +1 ;
}
else {end=mid;}

}
return nums[start];

    }
};

Approach 2:

class Solution {
public:
    int findMin(vector<int>& nums) {
int start  = 0 ;
int n = nums.size();
int end  = nums.size() -1; 
while(start<end){
int mid = start +( end-start)/2 ; 
if(nums[start] <nums[end]){
return nums[start];}

if(nums[mid] < nums[(mid+1)%n]  && nums[mid] < nums[(mid+ n -1)%n]){
return nums[mid] ;}
else if(nums[start]<=nums[mid]){
start = mid +1 ;}

else {end = mid ;}
}
return nums[start];

    }
};

