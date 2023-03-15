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
    int getLength(ListNode *head)
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
    ListNode *reverse(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (head == NULL)
        {
            return true;
        }
        if (head->next == NULL)
        {
            return true;
        }
        if (head->val != head->next->val && head->next->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        ListNode *mid = slow;
        if (getLength(head) % 2)
        {
            ListNode *curr = head;
            ListNode *newNode = reverse(mid->next);
            mid->next = newNode;
            while (newNode != NULL)
            {
                if (curr->val != newNode->val)
                {
                    return false;
                }
                curr = curr->next;
                newNode = newNode->next;
            }

            return true;
        }

        else
        {
            ListNode *curr = head;
            while (curr->next != mid)
            {
                curr = curr->next;
            }
            ListNode *foreven = curr;
            ListNode *newNode = reverse(mid);
            foreven->next = newNode;
            curr = head;
            while (newNode != NULL)
            {
                if (curr->val != newNode->val)
                {
                    return false;
                }
                curr = curr->next;
                newNode = newNode->next;
            }
            return true;
        }
    }
};