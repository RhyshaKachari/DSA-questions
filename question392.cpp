// Jump Game III - Leetcode

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(start);
        vis[start] = 1;
        while (!q.empty())
        {
            int pos = q.front();
            q.pop();
            if (arr[pos] == 0)
            {
                return true;
            }
            // forward
            int fwd = pos + arr[pos];
            int bck = pos - arr[pos];
            if (fwd < n && fwd >= 0 && vis[fwd] != 1)
            {
                q.push(fwd);
                vis[fwd] = 1;
            }
            // backward
            if (bck >= 0 && bck < n && vis[bck] != 1)
            {
                q.push(bck);
                vis[bck] = 1;
            }
        }
        return false;
    }
};