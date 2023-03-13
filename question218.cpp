// Remove Duplicates from Sorted List - Leetcode

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *curr = head;
        while (curr != NULL)
        {
            // if same value
            if ((curr->next != NULL) && (curr->val == curr->next->val))
            {
                ListNode *todel = curr->next;
                curr->next = todel->next;
                todel->next = NULL;
                delete (todel);
            }
            // if different value
            else
            {
                curr = curr->next;
            }
        }
        return head;
    }
};