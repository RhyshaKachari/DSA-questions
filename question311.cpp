// Add Two Numbers II - Leetcode

// Time Complexity -  O(N+M)
// Space Complexity = O(Max(N,M)) for the resultant list.

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *fwd;
        while (curr != NULL)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *nl1 = reverseList(l1);
        ListNode *nl2 = reverseList(l2);
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        int carry = 0;
        while (nl1 != NULL || nl2 != NULL || carry)
        {
            int sum = 0;
            if (nl1 != NULL)
            {
                sum += nl1->val;
                nl1 = nl1->next;
            }
            if (nl2 != NULL)
            {
                sum += nl2->val;
                nl2 = nl2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *nn = new ListNode(sum % 10);
            temp->next = nn;
            temp = temp->next;
        }
        return reverseList(dummy->next);
    }
};
