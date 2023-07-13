//Binary Tree Maximum Path Sum - Leetcode
//Time Complexity - O(N)
//Space Complexity - O(N)recursive

class Solution {
public:
     int dfs(TreeNode* root , int &maxi){
        if(root == NULL){
            return 0 ;
        }
        int lh = max(dfs(root->left , maxi),  0) ;
        int rh = max(dfs(root->right , maxi ) , 0) ;
        maxi = max(maxi ,root->val+lh+rh);
        return max(lh , rh) + root->val ;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        dfs(root , maxi);
        return maxi ;
    }
};