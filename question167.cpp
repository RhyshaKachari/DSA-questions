// Check if array is sorted - GFG
// Time Compelxity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    bool arraySortedOrNot(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};