// N meetings in one room -  GFG

// Approach 1 : Greedy Approach - We will sort all the meetings in increasing order of their end times. A meeting can be held if the start time of it is greater than the end time of the previous meeting

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        sort(v.begin(), v.end(), cmp);
        int cnt = 1;
        int endTime = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first > endTime)
            {
                cnt++;
                endTime = v[i].second;
            }
        }
        return cnt;
    }
}