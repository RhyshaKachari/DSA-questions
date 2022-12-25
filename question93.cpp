//Binary Tree Preorder Traversal - Leetcode
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution{
public:
void recur(TreeNode* root , vector<int> &v){
if (root == NULL)
{return;
}
v.push_back(root->data);
recur(root->left , v);
recur(root->right , v);

}

vector<int> preorderTraversal(TreeNode* root){
vector<int>v;
recur(root , v);
return v;

}
};