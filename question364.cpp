// Rotate a Linked List - GFG (by left)

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    
    Node *rotate(Node *head, int k)
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = head;
        int cnt = 1;
        Node *temp = head;
        while (cnt < k)
        {
            temp = temp->next;
            cnt++;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};