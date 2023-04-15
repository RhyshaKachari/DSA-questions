// Chocolate Distribution Problem - GFG

// Time Complexity  = O(n log n )
// Space Complexity = O(1)

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long i = 0;
        long long j = m - 1;
        long long mini = __INT32_MAX__;
        while (j < n)
        {
            mini = min(a[j] - a[i], mini);
            j++;
            i++;
        }
        return mini;
    }
};