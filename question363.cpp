// Merge two sorted linked lists -  GFG

// Approach 1 : Creating a new list
// Time Complexity :O(N+M)
// Space Complexity :O(N+M)

// Approach 2 :
//  Expected Time Complexity : O(n+m)
//  Expected Auxilliary Space : O(1)

void swap(Node *&l1, Node *&l2)
{
    Node *temp = l1;
    l1 = l2;
    l2 = temp;
}

Node *sortedMerge(Node *head1, Node *head2)
{
    Node *l1 = head1;
    Node *l2 = head2;
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }
    Node *res = l1;
    while (l1 != NULL && l2 != NULL)
    {
        Node *temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}