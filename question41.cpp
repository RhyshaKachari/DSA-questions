Searching in a Nearly Sorted Array - Aditya Verma 

class Solution{
public:
int search(vector<int> &nums , int target) {
int start = 0; 
int end = nums.size() -1;
while(start <= end){
int mid = start + (end-start)/2 ;
if(nums[mid] == target ){return mid;}
else if(mid-1 >start && nums[mid-1] == target){return mid-1;}
else if(mid+1<end && nums[mid+1] ==  target){return mid+1;}
else if(target < nums[mid]){end = mid-2 ;}
else{start = mid+2;}
}
return -1;
}
};



