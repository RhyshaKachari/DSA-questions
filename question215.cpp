// Linked List Cycle II - Leetcode

// Time Complexity : O(n)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if (head->next == NULL)
        {
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        //    ListNode* ans = NULL;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {
                while (slow != head)
                {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

// Find the first node of loop in linked list - GFG

// Time Complexity = O(n)
// Space Complexity = O(1)


class Solution
{
public:
    int findFirstNode(Node *head)
    {
        if (head == NULL)
        {
            return -1;
        }
        if (head->next == NULL)
        {
            return -1;
        }

        Node *fast = head;
        Node *slow = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->nest;
                    fast = fast->next;
                }
                return slow->data;
            }
        }
        return -1;
    }
};