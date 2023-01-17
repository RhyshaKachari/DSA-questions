// Kth smallest element - GFG
// Time Complexity = O(n)
// Space Complexity = O(log n)

class Solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        priority_queue<int> maxH;
        for (int i = l; i <= r; i++)
        {
            maxH.push(arr[i]);
            if (maxH.size() > k)
            {
                maxH.pop();
            }
        }
        return maxH.top();
    }
};
