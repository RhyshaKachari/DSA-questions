// Baseball Game - Leetcode
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        int n = operations.size();
        for (int i = 0; i < n; i++)
        {
            if (operations[i] == "+")
            {
                int first = st.top();
                st.pop();
                int sec = st.top();
                int sum = first + sec;
                st.push(first);
                st.push(sum);
            }

            else if (operations[i] == "D")
            {
                int ne = 2 * st.top();
                st.push(ne);
            }

            else if (operations[i] == "C")
            {
                st.pop();
            }
            else
            {
                int val = stoi(operations[i]);
                st.push(val);
            }
        }
        int tot = 0;
        while (st.size() > 0)
        {
            tot = tot + st.top();
            st.pop();
        }
        return tot;
    }
};
