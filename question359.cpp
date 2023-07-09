// Validate Binary Search Tree - Leetcode

// Time Complexity = O(N)
// Space Complexity = O(1) + O(N) Recursive

class Solution
{
public:
    bool isValid(TreeNode *node, long long int low, long long int high)
    {
        if (node == NULL)
        {
            return true;
        }
        if (node->val <= low || node->val >= high)
        {
            return false;
        }

        return isValid(node->left, low, node->val) && isValid(node->right, node->val, high);
    }
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};