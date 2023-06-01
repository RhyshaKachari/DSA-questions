// Implementing lower bound using Binary search - CP by Luv

// Time Complexity = O(log n)
// Space Complexity = O(n)

class Solution
{
public:
    int lowerBound(vector<int> &v, int element)
    {
        // we will assume that v is sorted
        int low = 0;
        int high = v.size() - 1;
        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            if (v[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        if (v[low] >= element)
        {
            return low;
        }
        if (v[high] >= element)
        {
            return high;
        }
        return -1;
        
    }
};