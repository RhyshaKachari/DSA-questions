// Implementing Upper Bound using Binary Search - Cp by luv

// Time Complexity = O(log n)
// Space Complexity =  O(1)

int upperbound(vector<int> &v, int element)
{
    int low = 0;
    int high = v.size() - 1;
    while (high - low > 1)
    {
        int mid = (low + high) / 2;
        if (v[mid] <= element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] > element)
    {
        retun low;
    }
    if (v[high] > element)
    {
        return high;
    }

    return -1;
};