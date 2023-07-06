// Nodes at given distance in binary tree - GFG

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
private:
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

public:
    vector<int> KDistanceNodes(Node *root, int targt, int k)
    {
        // mark the parents
        unordered_map<Node *, Node *> parents;
        Node *target = markParents(root, parents, targt);

        // making a visited map
        unordered_map<Node *, bool> visited;
        // now doing the bfs traversal
        queue<Node *> q;
        int cur_level = 0;
        q.push(target);
        visited[target] = true;
        while (!q.empty())
        {
            int size = q.size();
            if (cur_level++ == k)
            {
                break;
            }
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if (parents[node] && !visited[parents[node]])
                {
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
