// Two Sum IV - Input is a BST
// Time Complexity - O(N)
// Space Complexity - O(H)*2

class BSTIterator
{
  stack<TreeNode *> myStack;
  bool reverse = true;
  // reverse ->true = before
  // reverse ->false = next

public:
  BSTIterator(TreeNode *root, bool isReverse)
  {
    reverse = isReverse;
    pushAll(root);
  }

  bool hasNext()
  {
    return !myStack.empty();
  }

  int next()
  {
    TreeNode *temp = myStack.top();
    myStack.pop();
    if (!reverse)
    {
      pushAll(temp->right);
    }
    else
    {
      pushAll(temp->left);
    }
    return temp->val;
  }

private:
  void pushAll(TreeNode *root)
  {
    while (root)
    {
      myStack.push(root);
      if (reverse)
      {
        root = root->right;
      }
      else
      {
        root = root->left;
      }
    }
  }
};
class Solution
{
public:
  bool findTarget(TreeNode *root, int k)
  {
    if (!root)
    {
      return false;
    }
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j)
    {
      if (i + j == k)
      {
        return true;
      }
      else if (i + j < k)
      {
        i = l.next();
      }
      else
      {
        j = r.next();
      }
    }
    return false;
  }
};