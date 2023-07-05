// Maximum Width of Tree - GFG
// Time Compelxity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int getMaxWidth(Node *root)
    {

        int ans = 0;
        queue<Node *> q;
        q.push({root});
        while (!q.empty())
        {
            int size = q.size();
            ans = max(ans, size);
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};