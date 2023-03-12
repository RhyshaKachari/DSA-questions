// Reverse Nodes in K Group - Leetcode

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    ListNode *solve(ListNode *head, int k)
    {

        // base condition
        if (head == NULL)
        {
            return head;
        }
        // reverse first k nodes
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *fwd = NULL;
        ListNode *check = curr;
        int t = 0;
        while (t < k && check != NULL)
        {
            check = check->next;
            t++;
        }
        if (t < k)
        {
            return curr;
        }
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            cnt++;
        }

        // Recursion
        if (fwd != NULL)
        {
            head->next = solve(fwd, k);
        }
        // return head of reversed list
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        return solve(head, k);
    }
};