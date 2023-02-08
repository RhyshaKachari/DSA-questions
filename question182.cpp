// Plus One - Leetcode
// Time Complexity =  O(n)
// Space Complexity = O(n)

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int nine = 0;
        int n = digits.size();
        for (int i = 0; i < n; i++)
        {
            if (digits[i] == 9)
            {
                nine++;
            }
        }

        if (nine == n)
        {
            digits.push_back(0);
            digits[0] = 1;
            for (int i = 1; i < digits.size(); i++)
            {
                digits[i] = 0;
            }
            return digits;
        }

        int j = n - 1;
        if (digits[j] < 9)
        {
            digits[j] = digits[j] + 1;
        }
        else
        {
            while (digits[j] == 9)
            {
                j--;
            }
            digits[j] = digits[j] + 1;
        }
        return digits;
    }
};
