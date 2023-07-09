// Remove Nth Node from End of List - Leetcode

// Approach 1 : Using the length of the linked list
//  Time Complexity = O(N)
//  Space Complexity = O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        if (n == cnt)
        {
            return head->next;
        }
        int c = cnt - n;

        ListNode *node = NULL;
        cnt = 1;
        ListNode *curr = head;
        while (cnt < c)
        {
            curr = curr->next;
            cnt++;
        }
        node = curr->next;
        curr->next = node->next;
        node->next = NULL;
        delete node;
        return head;
    }
};

// Approach 2 : Using fast and slow pointer
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *slow = start;
        ListNode *fast = start;
        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return start->next;
    }
};