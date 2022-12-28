//Same Tree - Leetcode
//Time Complexity = O(N)
//Space Complexity = O(1) Extra Space + O(H) Height of the tree

class Solution{
public:
  bool isSameTree(TreeNode* p , TreeNode* q){
  if ((p == NULL) && (q == NULL))
  {return true;
  }
  else if ((p == NULL) || ( q == NULL))
  {return false;
  }
  
  return((p->val == q->val) && isSameTree(p->left , q->left) && isSameTree(p->right , q->right));


  }

};