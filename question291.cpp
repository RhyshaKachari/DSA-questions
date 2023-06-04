// Minimum Number of Days to Make m Bouquets - Leetcode

// Time Complexity :O(N.log(maxVal)), where maxVal = max(bloomDay)
// Space Complexity : O(1)

class Solution
{
public:
    bool ifPossible(vector<int> &bloomDay, int m, int k, int mid)
    {
        int adj = 0;
        int bc = 0;
        for (auto it : bloomDay)
        {
            if (it <= mid)
            {
                adj++;
                if (adj == k)
                {
                    bc++;
                    if (bc == m)
                    {
                        return true;
                    }
                    adj = 0;
                }
            }
            else
            {
                adj = 0;
            }
        }
        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
         // if(m*k > bloomDay.size()){
        //     return -1;
        // }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        int ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (ifPossible(bloomDay, m, k, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};