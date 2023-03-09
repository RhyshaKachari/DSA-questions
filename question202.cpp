// Search in Linked List - GFG

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    bool searchKey(int n, struct Node *head, int key)
    {
        int flag = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        if (flag == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}