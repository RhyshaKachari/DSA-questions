// Lowest Common Ancestor of a Binary Tree - Leetcode

// Time Complexity - O(N)
// Space Complexity - O(H) which will be O(N) in worst case scenario of a skew tree

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || p == root || q == root)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};
