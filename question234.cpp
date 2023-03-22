// Search in a Binary Search Tree - Leetcode

// Time Complexity = O(height of tree)
// Space Complexity = O(1)

class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != NULL && root->val != val)
        {
            if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return root;
    }
};