// Delete a node from BST -  GFG
//Time Complexity : O(Height of the BST)
//Space Complexity : O(Height of the BST) auxillary


Node *findlastRight(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findlastRight(root->right);
}

Node *helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->left;
    }
    Node *rightChild = root->right;
    Node *lastRight = findlastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

Node *deleteNode(Node *root, int X)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == X)
    {
        return helper(root);
    }
    Node *dummy = root;
    while (root)
    {
        if (root->data > X)
        {
            if (root->left != NULL && root->left->data == X)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right != NULL && root->right->data == X)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}