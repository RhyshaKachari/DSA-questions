// Delete node in Doubly Linked List - GFG

// Time Complexity  = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    Node *deleteNode(Node *head_Ref, int x)
    {
        if (x == 1)
        {
            head_Ref = head_Ref->next;
            head_Ref->prev = NULL;
        }
        else
        {
            Node *curr = head_Ref;
            Node *temp = NULL;
            int cnt = 1;
            while (cnt < x)
            {
                temp = curr;
                curr = curr->next;
                cnt++;
            }
            temp->next = curr->next;
            // temp->next->prev = temp;
            curr->next = NULL;
            curr->prev = NULL;
            return head_Ref;
        }
    }
};