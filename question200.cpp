// Delete a Node in Single Linked List - GFG

// Time Complexity = O(n)
// Space Complexity = O(n)

Node *deleteNode(Node *head, int x)
{
    if (x == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        return head;
    }

    else
    {
        int cnt = 1;
        Node *curr = head;
        Node *prev = NULL;
        while (cnt < x)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        return head;
    }
}