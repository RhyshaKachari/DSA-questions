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

// Approach 2 :
//Time Complexity - O(1)
//Space Complexity - O(1)

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        // No condition
        if (M > N || (N * 6 < M * 7 && S > 6))
        {
            return -1;
        }
        int days = S * M / N;
        if (S * M % N)
        {
            return days + 1;
        }
        else
        {
            return days;
        }
    }
}