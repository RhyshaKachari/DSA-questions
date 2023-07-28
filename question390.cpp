// Maximum Units on a Truck - Leetcode

// Time Complexity - O(n log n)
// Space Complexity - O(1)

class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int result = 0;
        for (auto it : boxTypes)
        {
            if (truckSize < it[0])
            {
                result += (truckSize * it[1]);
                break;
            }
            else
            {
                result += (it[0] * it[1]);
                truckSize -= it[0];
            }
        }
        return result;
    }
};