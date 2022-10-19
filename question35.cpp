Best Time to Buy and Sell Stock - Leetcode
Easy

Approach 1 :  Brute Force 
Time Complexity = O(n^2)
Space Complexity = O(1) 

class Solution{
public:
int maxProfit(vector<int> &prices){
int max = 0;
int diff = 0;
for(int i = 0 ; i < prices.size() ; i++){
for(int j = i; j < prices.size() ; j++){
diff = prices[j] - prices[i];
if(max <diff){
max = diff;}
}
}
return max;
}
};

Approach 2 :  Creating another array storing highest prices
Time Complexity  :  O(n)  , Space Complexity = O(n)


class Solution {
public:
    int maxProfit(vector<int>& prices) {
  int aux[prices.size()];
int maxPrice = prices[prices.size() -1];
for(int i = prices.size()-1 ; i >= 0 ; i--){
if(i == prices.size() -1){
aux[i] =  prices[prices.size() -1];}
else if(prices[i] > maxPrice){
maxPrice = prices[i];
aux[i] = maxPrice ; }

else aux[i] = maxPrice ;
}

int maxProfit = 0;
for(int i = 0 ; i <prices.size() ; i++){
if(aux[i] - prices[i] >maxProfit){
maxProfit = aux[i] - prices[i];}
}
return maxProfit;

  
    }
};


Approach 3 :  Two variable approach
Time Complecity = O(n) , Space Complexity = O(1)

class Solution{
public:
int maxProfit(vector<int> &prices){
int minSoFar = prices[0];
int maxProfit = 0;
for(int i = 0 ; i < prices.size() ; i++){
if(prices[i] < minSoFar){
minSoFar = prices[i];
}
if(maxProfit < prices[i] - minSoFar){
maxProfit = prices[i] - minSoFar ;
}
}
return maxProfit ;
}
};



