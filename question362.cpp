// Inorder Successor in BST- GFG

// Approach 1 : We know that the inorder of a bst is in sorted order so we will traverse the entire bst and sort the nodes and then return the successor of the given input

// Time Complexity - O(N)+O(N)
// Space Complexity - O(N)

class Solution
{
public:
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        vector<int> inorder;
        stack<Node *> st;
        Node *curr = root;
        while (true)
        {
            if (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if (st.size() == 0)
                {
                    break;
                }
                else
                {
                    curr = st.top();
                    inorder.push_back(curr->data);
                    st.pop();
                    curr = curr->right;
                }
            }
        }

        int ind = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == x->data)
            {
                ind = i;
                break;
            }
        }
        if (ind == inorder.size() - 1)
        {
            return new Node(-1);
        }
        else
        {
            return new Node(inorder[ind + 1]);
        }
    }
};

// Approach 2 : using the property of BST
// Time Complexity - O(H)
// Space Complexity - O(1)

class Solution
{
public:
    Node *inOrderSuccessor(Node *root, Node *x)
    {
        Node *curr = root;
        Node *suc = NULL;
        while (curr)
        {
            if (curr->data <= x->data)
            {
                curr = curr->right;
            }
            else if (curr->data > x->data)
            {
                suc = curr;
                curr = curr->left;
            }
        }
        return suc;
    }
};