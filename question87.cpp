// Maximal Rectangle - Leetcode Aditya Verma
// Time Complexity = O(n^2)
// Space Complecity = O(n^2)

class Solution
{
public:
    vector<int> leftArray(vector<int> &arr)
    {
        vector<int> left;
        stack<pair<int, int>> s;
        int n = arr.size();
        int pseudo = -1;
        for (int i = 0; i < n; i++)
        {
            if (s.size() == 0)
            {
                left.push_back(pseudo);
            }
            else if (s.top().first < arr[i])
            {
                left.push_back(s.top().second);
            }
            else
            {
                while (s.size() > 0 && s.top().first >= arr[i])
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
            s.push({arr[i], i});
        }
        return left;
    }

    vector<int> rightArray(vector<int> &arr)
    {
        vector<int> right;
        stack<pair<int, int>> st;
        int n = arr.size();
        int pseudo = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.size() == 0)
            {
                right.push_back(pseudo);
            }
            else if (st.top().first < arr[i])
            {
                right.push_back(st.top().second);
            }
            else
            {
                while (st.size() > 0 && st.top().first >= arr[i])
                {
                    st.pop();
                }
                if (st.size() == 0)
                {
                    right.push_back(pseudo);
                }
                else
                {
                    right.push_back(st.top().second);
                }
            }
            st.push({arr[i], i});
        }
        reverse(right.begin(), right.end());
        return right;
    }

    int mah(vector<int> &arr)
    {
        vector<int> left;
        vector<int> right;
        vector<int> width;
        left = leftArray(arr);
        right = rightArray(arr);
        for (int i = 0; i < arr.size(); i++)
        { int w = (right[i] -  left[i]-1) *arr[i] ;
            width.push_back(w);
        }
        int max = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (width[i] > width[max])
            {
                max = i;
            }
        }
        return width[max];
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {  int  n = matrix.size();
       int m = matrix[0].size();
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == '0')
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }
        int mx = mah(v);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                {
                    v[j] = 0;
                }
                else
                {
                    v[j] = v[j] + 1;
                }
            }
            mx = max(mx, mah(v));
        }
        return mx;
    }
};