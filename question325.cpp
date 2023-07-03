// Sum of All Odd Length Subarrays - Leetcode
// Time complexity - O(n)
// Space complexity - O(1)

// for even substrings = T/2
// for odd substrings = T+1 /2

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (((n - i) * (i + 1) + 1) / 2) * arr[i];
        }
        return sum;
    }
};