Search in Rotated Sorted Array - Leetcode
Medium
Time Complexity = O(log n)  , Space Complexity = O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 ;
int end = nums.size() -1;
while(start<=end){
int mid = start + (end-start)/2 ;
if(nums[mid] == target) return mid;

//the left side is sorted
if(nums[start] <= nums[mid]){
//figure out if the element lies on the left half or not
if(target >= nums[start] && target <= nums[mid]){
end = mid-1;}
else{start = mid +1;}

}//right part is sorted
else{
if(target >= nums[mid]  &&  target <= nums[end]){
start = mid+1;
}
else {end = mid-1;}
}


}
return -1;

    }
};
