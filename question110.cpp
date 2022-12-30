// Left View of Binary Tree
// Time Complexity = O(N)
// Space Complexity = O(H)

void recursion(Node *root, int level, vector<int> &res)
{
    if (root == NULL)
    {
        return;
    }
    if (res.size() == level)
    {
        res.push_back(root->data);
    }
    recursion(root->left, level + 1, res);
    recursion(root->right, level + 1, res);
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    recursion(root, 0, res);
    return res;
}
