//Max Sum Subarray of size K -GFG

//Approach 1 : 
//Time Complexity : O(n^2)
//Space Complexity : O(1)

class Solution{
    public:
    long maximumSumSubarray(int k , vector<int> &arr , int N){
       long int mx = INT_MIN ;
       
       for(int i = 0 ; i <= n-k ; i++){
        long int sum = 0;
        for(int j = i ; j < i+k ; j++ ){
           sum = sum + arr[j];
          } mx = max(mx , sum);
       } 
       return mx ;
    }
};


//Approach 2 : 
//Time Complexity : O(n)
//Space Complexity : O(1)
class Solution{
    public:
    long maximumSumSubarray(int K , vector<int> &arr , int N){
       long int mx = INT_MIN;
        int i = 0; 
        int j = 0;
       long int sum = 0;
        while (j<N)
        { sum = sum + arr[j];
           if(j-i+1 < K){
           j++;
           }
           else if(j-i+1 == K){
            mx = max(mx ,sum);
            sum = sum - arr[j];
            i++;
            j++;
           }
        }
        return mx;
    }
};