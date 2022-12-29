// Binary Tree ZigZag Level Order Traversal - Leetcode
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;

        queue<TreeNode *> q;
        bool flag = 0;
        if (node == NULL)
        {
            return ans;
        }

        q.push(root);
        while (!q.empty())
        {
            vector<int> v;
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                v.push_back(node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            if (flag)
            {
                reverse(v.begin(), v.end());
            }

            ans.push_back(v);
            flag = !flag;
        }
        return ans;
    }
};