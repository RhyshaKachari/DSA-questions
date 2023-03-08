// Linked List Insertion - GFG

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    Node *insertAtBeginning(Node *&head, int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
    }

    Node *insertAtEnd(Node *&head, int x)
    {
        if (!head)
        {
            return new Node(x);
        }
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node *temp = new Node(x);
        curr->next = temp;
    }
}