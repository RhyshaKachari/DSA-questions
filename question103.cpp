// Diameter of a Binary Tree -GFG
// Time Complexity = O(N)
// Space Complexity = O(1) Extra Space , O(H) Recursion Stack Space where H is the height of tree

class Solution
{
public:
    int height(Node *root, int &d)
    {
        if (!root)
        {
            return 0;
        }
        int lh = height(root->left, d);
        int rh = height(root->right, d);
        d = max(d, (lh + rh + 1)); // emphasis on this line
        return (max(lh, rh) + 1);
    }

    int diameter(Node *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};



// Diameter of Binary Tree - Leetcode
//  Time Complexity = O(N)
//  Space Complexity = O(1) Extra Space , O(H) Recursion Stack Space where H is the height of tree

class Solution
{
public:
    int height(TreeNode *root, int &d)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height(root->left, d);
        int rh = height(root->right, d);
        d = max(d, (lh + rh));
        return (1 + max(lh, rh));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int d = 0;
        height(root, d);
        return d;
    }
};
