// Best Time to Buy and Sell Stock - Leetcode

// Approach 1 : Run two loops and calculate the maximum profit
// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mxprofit = INT_MIN;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (prices[j] > prices[i])
                {
                    mxprofit = max(mxprofit, prices[j] - prices[i]);
                }
            }
        }
        return mxprofit;
    }
};

// Approach 2 : Calculate minsofar and calculate maxprofit
// Time Complexity  : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minsofar = INT_MAX;
        int mxProfit = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            minsofar = min(minsofar, prices[i]);
            mxProfit = max(mxProfit, prices[i] - minsofar);
        }
        return mxProfit;
    }
};