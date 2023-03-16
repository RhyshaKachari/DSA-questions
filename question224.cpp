// Remove Nth Node from End of List - Leetcode

// Approach 1 : Using the length of the linked list
//  Time Complexity = O(N)
//  Space Complexity = O(1)

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

// Approach 2 : Using fast and slow pointer
//Time Complexity = O(n)
//Space Complexity = O(1)

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        while (n--)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            return head->next;
        }
        ListNode *slow = head;
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *todel = slow->next;
        slow->next = todel->next;
        todel->next = NULL;
        delete todel;
        return head;
    }
};