// Intersection of Two Linked Lists - GFG

// Time Complexity - O(m+n)
// Space Complexity - O(m+n)


class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        unordered_set<int> st;
        Node *temp = head2;
        while (temp != NULL)
        {
            st.insert(temp->data);
            temp = temp->next;
        }

        Node *dummy = new Node(0);
        Node *curr = dummy;
        temp = head1;
        while (temp != NULL)
        {
            if (st.find(temp->data) != st.end())
            {
                curr->next = new Node(temp->data);
                curr = curr->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};