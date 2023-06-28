// Delete node in Doubly Linked List - GFG

// Time Complexity  = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    Node *deleteNode(Node *head_ref, int x)
    {
        if (x == 1)
        {
            Node *temp = head_ref;
            head_ref = head_ref->next;
            head_ref->prev = NULL;
            temp->next = NULL;
            free(temp);
        }
        else
        {
            int cnt = 1;
            Node *temp = head_ref;
            Node *prev = NULL;
            while (cnt < x)
            {
                prev = temp;
                temp = temp->next;
                cnt++;
            }

            prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }

            free(temp);
            temp = NULL;
        }
        return head_ref;
    }
};