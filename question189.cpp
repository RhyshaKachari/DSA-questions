// Pass the Pillow -  Leetcode

// Time Complexity =  O(1)
// Space Complexity = O(1)

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int q = time / (n - 1);
        int r = time % (n - 1);
        if (q % 2)
        {
            return n - r;
        }
        else
            return r + 1;
    }
}