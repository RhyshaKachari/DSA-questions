//Search a node in BST - GFG

//Time Complexity = O(Height of the tree)
//Space Complexity = O(1)

bool search(Node *root, int x)
{
    while (root != NULL && root->data != x)
    {
        if (x < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}