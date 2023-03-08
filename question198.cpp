// Introduction to Linked List - GFG

// Time Complexity =  O(n)
// Space Complexity = O(n)

class Soltuion
{
public:
    Node *constructLL(vector<int> &arr)
    {
        Node *head = new Node(arr[arr.size() - 1]);
        if (arr.size() == 1)
        {
            return head;
        }
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            Node *temp = new Node(arr[i]);
            temp->next = head;
            head = temp;
        }
    }
};