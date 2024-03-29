// Find Nth root of M - GFG

// Time Complexity - O(n* log n)
// Space Complexity - O(1)

class Solution
{
public:
    int NthRoot(int n, int m)
    {
        if (m == 0 || m == 1)
        {
            return m;
        }
        long long lo = 1;
        long long hi = m;
        long long mid;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;

            if (pow(mid, n) == m)
            {
                return mid;
            }
            else if (pow(mid, n) < m)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
};