//Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold - Leetcode
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i  = 0 ;
        int j = 0 ;
        int count = 0;
        int sum  = 0 ;

        while(j < arr.size()){
            sum += arr[j] ;
            if(j- i +1 < k){
                j++ ;
            }
            else if(j-i +1 == k){
                if(sum >= threshold*k){
                    count++;
                }
                sum -= arr[i] ;
                i++;
                j++;
            }
        }
        return count ;
    }
};