// Children Sum Parent - GFG
// Time Complexity - O(n)
// Space Complexity - O(n)

class Solution
{
public:
    int isSumProperty(Node *root)
    {
        if (root == NULL)
        {
            return 1;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        int child = 0;
        if (root->left)
        {
            child += root->left->data;
        }
        if (root->right)
        {
            child += root->right->data;
        }
        return (child == root->data && isSumProperty(root->left) && isSumProperty(root->right));
    }
};