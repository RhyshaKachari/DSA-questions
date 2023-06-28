// Reverse a Doubly Linked List -GFG

// Time Complexity = O(n)
// Space Complexity = O(1)

Node *reverseDLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;
}