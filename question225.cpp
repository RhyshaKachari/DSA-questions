// Nth node from end of linked list - GFG

// Time Complexity = O(n)
// Space Complexity = O(1)


int getLength(Node *&head)
{
    int cnt = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        cnt++;
    }
    return cnt;
}
int getNthFromLast(Node *head, int n)
{
    int len = getLength(head);
    if (n > len)
    {
        return -1;
    }
    Node *fast = head;
    Node *slow = head;
    while (n--)
    {
        fast = fast->next;
    }
    if (!fast)
    {
        return head->data;
    }

    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->next->data;
}