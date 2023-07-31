//Non-overlapping Intervals - Leetcode
//Time Complexity - O(N log n) + O(N)
//Space Complexity - O(N)

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0 || intervals.size() == 1)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> temp = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] < temp[1])
            {
                temp[1] = min(temp[1], it[1]);
            }
            else
            {
                merged.push_back(temp);
                temp = it;
            }
        }

        merged.push_back(temp);
        return intervals.size() - merged.size();
    }
};