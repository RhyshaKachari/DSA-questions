// Delete the Middle Node of a Linked List -  Leetcode

// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        if (head->next == NULL)
        {
            return NULL;
        }

        ListNode *fast = head->next;
        ListNode *slow = head;

        while (fast != NULL && slow != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        ListNode *curr = head;
        while ((curr->next != NULL) && curr->next != slow)
        {
            curr = curr->next;
        }
        curr->next = slow->next;
        slow->next = NULL;
        delete (slow);
        return head;
    }
};