// Odd Even Linked List - Leetcode
// Time Complexity = O(N)
//Space Complexity = O(1)

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return head;
        }
        ListNode *odd = head;

        ListNode *even = head->next;
        ListNode *head2 = even;
        ListNode *oddN = odd;
        ListNode *evenN = even;
        while (oddN->next != NULL && evenN->next != NULL)
        {
            oddN = odd->next->next;
            evenN = even->next->next;
            odd->next = oddN;
            even->next = evenN;
            odd = oddN;
            even = evenN;
        }
        if (odd->next != NULL && odd->next->next == NULL)
        {
            odd->next = NULL;
        }

        odd->next = head2;
        return head;
    }
};