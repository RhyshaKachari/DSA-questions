// Add 1 to a number represented as linked list - GFG

// Time Complexity - O(n)
// Space Complexity - O(1)

class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *fwd;
        while (curr != NULL)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

public:
    Node *addOne(Node *head)
    {
        Node *nh = reverse(head);
        Node *curr = nh;
        int carry = 1;
        Node *prev = NULL;
        while (curr != NULL)
        {
            int sum = curr->data + carry;
            carry = sum / 10;
            curr->data = sum % 10;
            prev = curr;
            curr = curr->next;
        }
        if (carry)
        {
            prev->next = new Node(carry);
        }
        return reverse(nh);
    }
};