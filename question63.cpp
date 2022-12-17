// Subarray with 0 sum - GFG
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> umap;
        int psum = 0;

        for (int i = 0; i < n; i++)
        {
            psum += arr[i];
            if (psum == 0)
            {
                return true;
            }
            if (umap.find(psum) != umap.end())
            {
                return true;
            }
            else
            {
                umap.insert(psum);
            }
        }

        return false;
    }
};