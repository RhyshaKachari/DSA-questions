// Construct Binary Search Tree from Preorder Traversal - Leetcode

// Approach 1 : We iterate through the array and place each node manually

// Time Complexity : O(N* N)
// Space Complexity : O(1)

// Appraoch 2 : We know that inorder traversal of a BST is in sorted order. So we can sort the array and get the inorder traversal and construct a unique binary tree from inorder and preorder traversal

// Time Complexity - O(Nlog N) + O(N)
// Space Complexity -  O(N)

// Approach 3 : Using the bound concept
// Time Compelxity - O(N)
// Space Complexity - O(1) + O(N)recursive

class Solution
{
public:
    TreeNode *build(vector<int> &a, int &i, int bound)
    {
        if (a.size() == i || a[i] > bound)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(a[i++]);
        root->left = build(a, i, root->val);
        root->right = build(a, i, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        int bound = INT_MAX;
        return build(preorder, i, bound);
    }
};