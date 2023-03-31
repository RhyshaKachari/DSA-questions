// Largest Odd Number in String - Leetcode

// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    string largestOddNumber(string num)
    {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if ((num[i] - '0') & 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};