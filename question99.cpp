// Set the rightmost unset bit - GFG
// Time Complecity = O(N)
// Space Complexity = O(1)
class Solution
{
public:
    long long int setBit(int N)
    {
        long long int n = N;
        long long count = 0;
        while (true)
        {
            if ((n & 1))
            {
                n = n >> 1;
                count++;
            }
            else
            {
                break;
            }
        }
        if (n == 0) //edge case
        {
            return N;
        }
        long long int one = 1;
        long long int mask = one << count;
        return (N | mask);
    }
};
