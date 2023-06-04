// Koko Eating Bananas - Leetcode

// Time Complexity -  O(log n*h)
// Space Complexity - O(1)

class Solution
{
public:
    bool timefunc(vector<int> &piles, int h, int mid)
    {
        int time = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            if (mid == 0) // because {1} me mid = 0 hoga
            {
                return false;
            }
            time += (piles[i] - 1) / mid + 1;
            if (time > h)
            {
                return false;
               
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        int low = 0;
        int high = *max_element(piles.begin(), piles.end());
        int mid;
        int ans = 0;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (timefunc(piles, h, mid))
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