//Largest Rectangle in Histogram - Leetcode Aditya Verma
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution
{
public:
    void reverse(vector<int> ans)
        vector<int> nsl(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> left;
        stack<pair<int, int>> s;
        int pseudo = -1;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                left.push_back(pseudo);
            }
            else if (s.top().first < heights[i])
            {
                left.push_back(s.top().second);
            }

            else
            {
                while (s.size() > 0 && s.top().first >= heights[i])
                {
                    s.pop();
                }
                if (s.size() == 0)
                {
                    left.push_back(pseudo);
                }
                else
                {
                    left.push_back(s.top().second);
                }
            }
            s.push({heights[i], i});
        }
        return left;
    }

    vector<int> nsr(vector<int> &heights)
    {
        vector<int> right;
        stack<pair<int, int>> si;
        int n = heights.size();
        int pseudo = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (si.size() == 0)
            {
                right.push_back(pseudo);
            }
            else if (si.top().first < heights[i])
            {
                right.push_back(si.top().second);
            }
            else
            {
                while (si.size() > 0 && si.top().first >= heights[i])
                {
                    si.pop();
                }
                if (si.size() == 0)
                {
                    right.push_back(pseudo);
                }
                else
                {
                    right.push_back(si.top().second);
                }
            }
            si.push({heights[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> left = nsl(heights);
        vector<int> right = nsr(heights);
        vector<int> width;
        for (int i = 0; i < heights.size(); i++)
        {
            int w = right[i] - left[i] - 1;
            width.push_back(w);
        }
        int max = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            width[i] = width[i] * heights[i];
            if (width[i] > width[max])
            {
                max = i;
            }
        }
        return width[max];
    }
};