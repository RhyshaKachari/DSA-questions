// Square root of a number - GFG

// Time Complexity -  O(log n)
// Space Complexity - O(1)

class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long int X = x;
        long long int low = 1;
        long long int high = x;
        long long int mid;
        while (high - low > 1)
        {
            mid = (low + high) / 2;
            if (mid * mid <= X)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};

// Sqrt(x) - Leetcode

// Time Complexity - O(log n)
// Space Complexity - O(1)

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        long long int low = 1;
        long long int high = x;
        long long int mid;
        while (high - low > 1)
        {
            mid = (low + high) / 2;
            if (mid * mid <= x)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }
};