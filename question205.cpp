// Introduction to Doubly Linked List - GFG

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    Node *constructDLL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *curr = head;
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            Node *temp = new Node(arr[i]);
            temp->prev = curr;
            curr->next = temp;
            curr = temp;
        }
        return head;
    }
};
