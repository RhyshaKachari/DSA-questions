Find an element in an infinite sorted array
Time Complexity = O(log n) , Space Complexity = O(1)

class Solution{
public:
 int search(vector<int> &nums , int target){
int start = 0 ;
int end = 1; 
while(target > end){
end = end *2 ;
}

while(start<=end){
int mid  = start + (end-start)/2 ;
if(nums[mid] == target){return mid;}
else if(target > nums[mid]){start = mid +1 ;}
else (end = mid -1;)
}
return -1;
}
};
