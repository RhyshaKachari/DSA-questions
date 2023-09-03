// Required Rooms - GFG

// Time Complexity - O(log(max(N,M)))
// Space Complexity - O(1)

class Solution
{
public:
    int solve(int n, int m)
    {
        if (m == 0)
        {
            return n;
        }
        return solve(m, n % m);
    }
    int rooms(int N, int M)
    {
        int gcd = solve(N, M);
        if (gcd <= N && gcd <= M && gcd != 1)
        {
            return (N / gcd) + (M / gcd);
        }
        return N + M;
    }
};