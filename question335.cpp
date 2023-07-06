// Root Equals Sum of Children - Leetcode
// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root->left->val + root->right->val == root->val)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};