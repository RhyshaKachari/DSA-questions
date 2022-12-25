//Binary Tree Inorder Traversal
//Time Complexity = O(N)
//Space Complexity = O(N)

class Solution{
public:
void recur(TreeNode* root , vector<int> &v){
    if(root == NULL){
        return;
    }
    recur(root->left , v);
    v.push_back(val);
    recur(root->right , v);
}

vector<int> inorderTraversal(TreeNode* root){
vector<int> v;
recur(root ,v);
return v;
}
};