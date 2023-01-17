// Kth smallest element - GFG
// Time Complexity = O(n log k)
// Space Complexity = O(k)

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
