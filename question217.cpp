// To remove loop from the linked list - GFG

// Time Complexity = O(n)
// Space Complexity = O(1)

void removeLoop(Node *head)
{
    if (head == NULL)
    {
        return;
    }

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}