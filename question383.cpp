// Construct Binary Tree from Preorder and Inorder Traversal - Leetcode

// Time Complexity - O(N log N)
// Space Complexity - O(N)

class Solution
{
public:
    TreeNode *construct(vector<int> &preorder, int pres, int pree, vector<int> &inorder, int ins, int ine, map<int, int> &mp)
    {
        if (pres > pree || ins > ine)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[pres]);
        int ele = mp[node->val];
        int nele = ele - ins;
        node->left = construct(preorder, pres + 1, pres + nele, inorder, ins, ele - 1, mp);
        node->right = construct(preorder, pres + nele + 1, pree, inorder, ele + 1, ine, mp);
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int prestart = 0;
        int preend = preorder.size() - 1;
        int instart = 0;
        int inend = inorder.size() - 1;
        map<int, int> mp;
        for (int i = 0; i <= inend; i++)
        {
            mp[inorder[i]] = i;
        }
        return construct(preorder, prestart, preend, inorder, instart, inend, mp);
    }
};