// Remove Nth Node from End of List - Leetcode

// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    int getLength(ListNode *&head)
    {
        int cnt = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            cnt++;
        }
        return cnt;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int tot = getLength(head);
        if (head == NULL)
        {
            return NULL;
        }
        if (n > tot)
        {
            ListNode *nn = new ListNode(-1);
            return nn;
        }

        int real = tot - n + 1;
        if (real == 1)
        {
            ListNode *temp = head;
            head = head->next;
            temp->next = NULL;
            return head;
        }
        int cnt = 1;
        ListNode *curr = head;
        ListNode *prev = NULL;
        while (cnt < real)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
        return head;
    }
};