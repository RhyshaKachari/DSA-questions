// Check if it is possible to survive on Island - GFG

// Time Complexity = O(1)
// Space Complexity = O(1)

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        int sundays = S / 7;

        int buyingDays = S - sundays;
        int totalFood = S * M;
        int ans = 0;
        if (totalFood % N == 0)
        {
            ans = totalFood / N;
        }
        else
        {
            ans = (totalFood / N) + 1;
        }

        if (ans <= buyingDays)
        {
            return ans;
        }
        else
            return -1;
    }
};