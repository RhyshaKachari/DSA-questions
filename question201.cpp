// Count nodes of linked list - GFG

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    int getCount(struct Node *head)
    {
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *temp = head;
            int cnt = 0;
            while (temp != NULL)
            {

                temp = temp->next;
                cnt++;
            }
            return cnt;
        }
    }
};