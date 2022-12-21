//Trapping Rain Water - Leetcode Aditya Verma
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
int trap(vector<int>& height) {
int n = height.size();
int mxl[n];
int mxr[n];
mxl[0] =height[0];
mxr[n-1]=height[n-1];
for(int i = 1 ; i  < n ; i++){
mxl[i] = max(mxl[i-1] , height[i]);
}
for(int i = n-2 ; i >= 0; i--){
mxr[i] = max(mxr[i+1] , height[i]);
}

int water[n];
int sum = 0;
for(int i = 0; i < n ; i ++){
water[i] = min(mxl[i] , mxr[i]) - height[i];
sum += water[i];
}
return sum;
  
    }
};