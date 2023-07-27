// Lemonade Change - Leetcode
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int n = bills.size();
        int fives = 0;
        int tens = 0;
        for (int i = 0; i < n; i++)
        {
            if (bills[i] == 5)
            {
                fives++;
            }
            else if (bills[i] == 10)
            {
                tens++;
                if (fives == 0)
                {
                    return false;
                }
                fives--;
            }
            else if (bills[i] == 20)
            {
                // two cases one 10 and one 5 or 3 fives
                if (fives < 3 && tens == 0)
                {
                    return false;
                }
                else if (tens > 0 && fives == 0)
                {
                    return false;
                }
                else if (tens > 0 && fives > 0)
                {
                    tens--;
                    fives--;
                }
                else
                {
                    fives -= 3;
                }
            }
        }
        return true;
    }
};