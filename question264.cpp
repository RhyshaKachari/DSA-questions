// Leaders in an array - GFG

// Approach 1 : Using two loops and checking for each element if there exists an element in its right which is greater than the current element

// Time Complexity = O(n^2)
// Space Complexity = O(1)

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            bool leader = true;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] > a[i])
                {
                    leader = false;
                    break;
                }
            }
            if (leader)
            {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};

// Approach 2 : Using stack and applying the ngr algorithm
// Time Complexity = O(n) + O(n)
//  Space Complexity = O(n)

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> v;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.size() == 0)
            {
                v.push_back(-1);
            }
            else if (st.size() > 0 && st.top() > a[i])
            {
                v.push_back(st.top());
            }
            else
            {
                while (st.size() > 0 && st.top() <= a[i])
                {
                    st.pop();
                }
                if (st.size() == 0)
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(st.top());
                }
            }
            st.push(a[i]);
        }
        reverse(v.begin(), v.end());
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == -1)
            {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};

// Approach 3 : We will iterate through the right and check if the current element is greater than the maxsofar

// Time Complexity = O(n) + O(n log n)
// Space Complexity = O(n)

class Solution
{
public:
    vector<int> leaders(int a[], int n)
    {
        int mxsofar = INT_MIN;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > mxsofar)
            {
                ans.push_back(a[i]);
            }
            mxsofar = max(mxsofar, a[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
}
