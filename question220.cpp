// Remove duplicates from an unsorted linked list - GFG

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    // Function to remove duplicates from unsorted linked list.
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        if (head->next == NULL)
        {
            return head;
        }
        unordered_map<int, int> mp;
        Node *curr = head;
        mp[curr->data]++;

        while (curr->next != NULL)
        {
            Node *temp = curr->next;
            // if already once
            if (mp[temp->data] > 0)
            {
                curr->next = temp->next;
                temp->next = NULL;
                delete (temp);
            }
            // when not present
            else
            {
                mp[temp->data]++;
                curr = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};