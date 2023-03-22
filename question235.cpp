// Minimum element in BST - GFG

// Time Complexity = O(Height of the BST)
// Space Complexity = O(1)

int minValue(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}