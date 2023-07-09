//Lowest Common Ancestor of a Binary Search Tree - Leetcode
//Time Complexity - O(H)
//Space Complexity - O(1) + O(N) recursive

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int curr = root->val;
        if (curr < p->val && curr < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else if (curr > p->val && curr > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return root;
        }
    }
};