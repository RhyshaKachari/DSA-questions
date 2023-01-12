// Overlaping Intervals - GFG

Approach 1 : Brute Force
// Time Complexity = O(nlog n) + O(n^2)
// Space Complexity = O(1)

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> *intervals)
    {
        vector << vector < int >>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {
            int start = intervals[0];
            int end = intervals[1];
            if (!ans.empty())
            {
                if (start <= ans.back().second)
                {
                    continue;
                }
            }
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    end = max(end, intervals[j][1]);
                }
            }
            end = max(end, intervals[i][1]);
            ans.push_back({start, end});
        }
        return ans;
    }
};

Approach 2 : Optimal Approach
// Time Complexity = O(nlog n) + O(n)
// Space Complexity = O(1)

class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        vector<vector<int>> merged;
        if (intervals.size() == 0)
        {
            return merged;
        }
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        for (auto it : intervals)
        {
            if (it[0] <= tempInterval[1])
            {
                tempInterval[1] = max(tempInterval[1], it[1]);
            }
            else
            {
                merged.push_back(tempInterval);
                tempInterval = it;
            }
        }
        merged.push_back(tempInterval);
        return merged;
    }
};