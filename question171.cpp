//Minimum Difference Element in a sorted array - Aditya Verma
//Time Complexity = O(log n)
//Space Complexity = O(1)

class Solution{
public:
int minDif(vector<int> &nums , int target){
int low = 0; 
int high = nums.size() - 1;
while(low <= high){
int mid = low + (high- low) /2 ;
if(nums[mid] == target){
return 0 ;
}
else if(nums[mid] < target){
low = mid +1 ;
}
else{ high = mid-1;}

}
int ans = min(abs(nums[low] - target) , abs(nums[high] - target)) ;
return ans;
}
};
