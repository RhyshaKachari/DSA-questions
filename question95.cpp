//Binary Tree Postorder Traversal - Leetcode
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution {
public:
void recur(TreeNode* root , vector<int> &v){
if(root == NULL){
return ;}
recur(root->left , v);
recur(root->right , v);
v.push_back(root->val);
}


    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> v;
recur(root , v);
return v;
 
    }
};