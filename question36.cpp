Best Time to Buy and Sell Stock II - Leetcode
Medium


Approach 1 
Time Complexity : O(n)  ,  Space Complexity :O(1)

class Solution{
public: 
int maxProfit(vector<int> &prices){
int maxProfit = 0 ; 
for(int i = 0 ;i < prices.size() ; i++ ){
if(prices[i] <prices[i+1]){
maxProfit =maxProfit +  prices[i+1] - prices[i];
}
}
return maxProfit ; 
}
};
