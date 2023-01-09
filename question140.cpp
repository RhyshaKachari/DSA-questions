// Maximum Rectangular Area in a Histogram - GFG
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
public:
    vector<int> nsl(long long arr[], int n)
    {
        vector<int> v;
        int pseudo = -1;
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                v.push_back(pseudo);
            }
            else if (s.size() > 0 && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else
            {
                while (s.size() > 0 && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(pseudo);
                }
                else
                {
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i], i});
        }
        return v;
    }

public:
    vector<int> nsr(long long arr[], int n)
    {
        vector<int> v;
        int pseudo = n;
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s.size() == 0)
            {
                v.push_back(pseudo);
            }
            else if (s.size() > 0 && s.top().first < arr[i])
            {
                v.push_back(s.top().second);
            }
            else
            {
                while (s.size() > 0 && s.top().first >= arr[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    v.push_back(pseudo);
                }
                else
                {
                    v.push_back(s.top().second);
                }
            }
            s.push({arr[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }

    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left = nsl(arr, n);
        vector<int> right = nsr(arr, n);
        vector<long long int> area;
        long long max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            long long int a = (right[i] - left[i] - 1) * arr[i];
            if (a > max)
            {
                max = a;
            }
        }
        return max;
    }
};