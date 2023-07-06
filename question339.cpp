// Burning Tree - GFG

// Time Complexity - O(N) + O(N)
// Space Complexity - O(N)

class Solution
{
public:
    Node *markParents(Node *root, unordered_map<Node *, Node *> &parents, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *res;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->data == target)
                {
                    res = node;
                }
                if (node->left)
                {
                    q.push(node->left);
                    parents[node->left] = node;
                }
                if (node->right)
                {
                    q.push(node->right);
                    parents[node->right] = node;
                }
            }
        }
        return res;
    }
    int minTime(Node *root, int target)
    {
        // marking the parents
        unordered_map<Node *, Node *> parents;
        Node *start = markParents(root, parents, target);

        // making a visited map
        unordered_map<Node *, bool> visited;
        // now doing the bfs traversal
        queue<Node *> q;
        int ans = 0;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int size = q.size();
            int fl = 0;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    fl = 1;
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if (node->right && !visited[node->right])
                {
                    fl = 1;
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if (parents[node] && !visited[parents[node]])
                {
                    fl = 1;
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
            if (fl)
            {
                ans++;
            }
        }
        return ans;
    }
};