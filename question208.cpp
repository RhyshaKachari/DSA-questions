// Reverse Linked List - Leetcode

// Approach 1 : Iterative Approach
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        else
        {
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *forw;
            while (curr != NULL)
            {
                forw = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forw;
            }
            return prev;
        }
    }
};

// Approach 2 : Recursive Approach
// Time Complexity = O(n)
// Space Complexity = O(n) recursive stack space

class Solution
{
public:
    void reversal(ListNode *&head, ListNode *prev, ListNode *curr)
    {
        // base case
        if (curr == NULL)
        {
            head = prev;
            return;
        }

        ListNode *fwd = curr->next;
        reversal(head, curr, fwd);
        curr->next = prev;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        reversal(head, prev, curr);
        return head;
    }
};

// Approach 3 : Recursion
// Time Complexity  : O(n)
// Space Complexity : O(n) recursive stack space

class Solution
{
public:
    ListNode *reverse1(ListNode *&head)
    {
        // base condition
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *chotahead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return chotahead;
    }

    ListNode *reverseList(ListNode *head)
    {
        return reverse1(head);
    }
};