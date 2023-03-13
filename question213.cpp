// Whether the given linked list is circular or not - Love Babbar

// Approach 1 :
// Time Complexity : O(n)
// Space Compelxity = O(1)

bool isCircular(Node *&head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }
    else
    {
        Node *curr = head->next;
        while (curr != head && curr != NULL)
        {
            curr = curr->next;
        }
        if (curr == head)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}