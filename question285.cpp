// Square root of a number upto 7 places using binary search - CP by luv

// Time Complexity - O(log n)
// Space Complexity - O(1)

class Solution
{
public:
    double esp = 1e-7;

    double sqrt(double x)
    {
        double lo = 1;
        double hi = x;
        double mid;
        while (hi - lo > esp)
        {
            mid = (lo + hi) / 2;
            if (mid * mid < x)
            {
                lo = mid;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
}