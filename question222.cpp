// Palindrome Linked List - Leetcode

// Approach 1 : Using an array
// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> v;
        ListNode *curr = head;
        while (curr != NULL)
        {
            v.push_back(curr->val);
            curr = curr->next;
        }

        int n = v.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (v[i] != v[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

// Approach 2 :
// Step 1 : Find the middle of the list
// Step 2 : Reverse the list from the middle node
// Step 3 : Check if both same
// Step 4 : Repeat the step 2

// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *fwd = NULL;
        while (curr != NULL)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *dummy = head;
        while (slow != NULL)
        {
            if (dummy->val != slow->val)
            {
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};