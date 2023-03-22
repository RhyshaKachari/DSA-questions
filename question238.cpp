// Insert into a Binary Search Tree -  Leetcode
// Time Complexity =  O(log n)
// Space Complexity = O(1)

class Solution
{
public:
    TreeNode *insetIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *curr = new TreeNode(val);
            return curr;
        }
        TreeNode *curr = root;
        while (true)
        {
            if (curr->val <= val)
            {
                if (curr->right != NULL)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else if (curr->val > val)
            {
                if (curr->left != NULL)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};