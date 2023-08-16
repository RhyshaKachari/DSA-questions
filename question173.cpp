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

//Approach 2 : Using quick select algortihm

//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution {
public:

    int partition(vector<int>&nums, int left ,int right){
        int pivot = nums[left] ;
        int l = left+1 ;
        int r = right ;
        while(l<=r){
            if(nums[l] < pivot && nums[r] > pivot){
                swap(nums[l] , nums[r]) ;
                l++ ;
                r-- ;
            }
            if(nums[l] >= pivot){
                l++ ;
            }
            if(nums[r] <= pivot){
                r-- ;
            }
        }
        swap(nums[left] , nums[r]) ;
        return r ;
    }

    int findKthLargest(vector<int>& nums, int k) {    int n = nums.size();
        int left = 0 ;
        int right = n-1 ;
        int kth ;
        while(1){
            int index = partition(nums , left , right) ;
            if(index == k-1){
                kth = nums[index] ;
                break ;
            }
            else if(index < k-1){
                left = index +1 ;
            }
            else{
                right = index-1 ;
            }
       }
       return kth ;
    }
};