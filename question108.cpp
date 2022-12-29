// Bottom View of Binary Tree - Leetcode
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        map<int, int> mp;
        if (root == NULL)
        {
            return ans;
        }
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            Node *node = p.first;
            int line = p.second;
            mp[line] = node->data;
            if (node->left)
            {
                q.push({node->left, line - 1});
            }
            if (node->right)
            {
                q.push({node->right, line + 1});
            }
        }
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};