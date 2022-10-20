 Find First and Last Position of Element in Sorted Array

Approach :  Binary Search
Time Complexity : O(log n) , Space Complexity : O(1)

class Solution {
public:
    int firstOccur(vector<int> &nums , int target){
int start =0;
int end = nums.size() -1;
int res = -1;
while(start<=end){
int mid = start + (end-start)/2 ;
if(nums[mid] == target){
res = mid ;
end = mid -1;}
else if(nums[mid]>target){
end = mid -1;}
else{start = mid+1;}
}
return res;
}

int endOccure(vector<int> &nums , int target){
int start =0;
int end = nums.size() -1 ;
int res = -1;
while(start<=end){
int mid = start + (end-start)/2 ;
if(nums[mid] == target){
res = mid ;
start = mid +1;}
else if(nums[mid]>target){
end = mid -1;}
else{start = mid+1;}
}
return res;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos;
      int first = firstOccur(nums , target) ;
int last = endOccure(nums , target);
pos.push_back(first) ;
pos.push_back(last);
return pos;
  
    }
};
