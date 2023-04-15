// Minimum Cost of ropes - GFG

// Time Complexity = O(n log n)
// Space Complexity = O(n)

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {
        priority_queue<long long, vector<long long>, greater<long long>> minH;
        for (long long i = 0; i < n; i++)
        {
            minH.push(arr[i]);
        }
        long long cost = 0;
        while (minH.size() > 1)
        {
            long long first = minH.top();
            minH.pop();
            long long second = minH.top();
            minH.pop();
            cost = cost + first + second;
            minH.push(first + second);
        }
        return cost;
    }
}