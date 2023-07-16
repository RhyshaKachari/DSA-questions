//Construct Binary Tree from Inorder and Postorder Traversal - Leetcode

//Time Complexity - O(N log N) 
//Space Complexity - O(N)

class Solution {
public:
    TreeNode* construct(vector<int>&inorder , int ins , int ine , vector<int>&postorder , int poss , int pose , map<int,int>&mp){
        if(poss>pose || ins>ine){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pose]) ;
        int elem = mp[root->val] ;
        int nelem = elem-ins ;
        root->left = construct(inorder ,ins,elem-1 , postorder , poss , poss+nelem-1 , mp);
        root->right = construct(inorder , elem+1 ,ine , postorder , poss+nelem , pose-1 ,mp);
        return root ;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int ,int >mp ;
        for(int i  = 0 ; i  < inorder.size() ; i++){ mp[inorder[i]] = i; }
        int ins = 0 ;
        int ine = inorder.size()-1 ;
        int poss = 0 ;
        int pose = postorder.size()-1 ;
        return construct(inorder , ins , ine , postorder , poss ,pose , mp);
    }
};