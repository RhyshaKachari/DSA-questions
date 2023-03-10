// Doubly Linked List Insertion at given position - GFG

// Time Complexity =  O(n)
// Space Complexity = O(1)

void addNode(Node *head, int pos, int data)
{
    Node *nn = new Node(data);
    for (int i = 0; i < pos; i++)
    {
        head = head->next;
    }
    nn->next = head->next;
    nn->prev = head;
    head->next = nn;
}
