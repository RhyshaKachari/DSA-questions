// Maximum Meetings in One Room - GFG
//Time Complexity - O(N*log(N))
//Space Complexity - O(N)

class Solution
{
public:
    struct meeting
    {
        int start;
        int end;
        int pos;
    };

    static bool cmp(struct meeting m1, struct meeting m2)
    {
        if (m1.end < m2.end)
        {
            return true;
        }
        else if (m1.end > m2.end)
        {
            return false;
        }
        else if (m1.pos < m2.pos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; i++)
        {
            meet[i].start = s[i];
            meet[i].end = f[i];
            meet[i].pos = i + 1;
        }

        sort(meet, meet + n, cmp);
        vector<int> meets;
        int limit = meet[0].end;
        meets.push_back(meet[0].pos);
        for (int i = 1; i < n; i++)
        {
            if (meet[i].start > limit)
            {
                meets.push_back(meet[i].pos);
                limit = meet[i].end;
            }
        }
        sort(meets.begin(), meets.end());
        return meets;
    }
};