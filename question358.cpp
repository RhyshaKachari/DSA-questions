// Postorder Traversal (Iterative) - GFG

// Approach 1 : Using 2 stacks
// first push root , left ,right in st1 and then push everything in st2
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> postOrder(Node *node)
    {
        vector<int> postorder;
        if (node == NULL)
        {
            return postorder;
        }
        stack<Node *> st1, st2;
        st1.push(node);
        while (!st1.empty())
        {
            Node *temp = st1.top();
            st1.pop();
            st2.push(temp);
            if (temp->left)
            {
                st1.push(temp->left);
            }
            if (temp->right)
            {
                st1.push(temp->right);
            }
        }

        while (!st2.empty())
        {
            Node *temp = st2.top();
            postorder.push_back(temp->data);
            st2.pop();
        }
        return postorder;
    }
};

// Approach 2 : Using one stack
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    vector<int> postOrder(Node *node)
    {
        vector<int> ans;
        if (node == NULL)
        {
            return ans;
        }

        Node *curr = node;
        stack<Node *> st;
        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                Node *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return ans;
    }
};