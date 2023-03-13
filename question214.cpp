// Linked List Cycle - Leetcode

// Approach 1 :
// Time Complexity = O(n)
// Space Complexity =  O(n)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        unordered_map<ListNode *, bool> mp;
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (mp[curr] == true)
            {
                return true;
            }
            mp[curr] = true;
            curr = curr->next;
        }
        return false;
    }
};

// Approach 2: Floyd Cycle Detection
// Time Complexity  = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
        {
            return false;
        }
        if (head->next == NULL)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
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
                return true;
            }
        }
        return false;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

                                                                                                                                                                                          // Detect Loop in linked list  - GFG

                                                                                                                                                                                          // Approach 1 : Using maps
                                                                                                                                                                                          // Time Complexity = O(n)
                                                                                                                                                                                          // Space Complexity =O(n)

                                                                                                                                                                                          class Solution
{
public:
    bool detectLoop(Node *head)
    {
        if (head == NULL)
        {
            return false;
        }
        unordered_map<Node *, bool> visited;
        Node *curr = head;
        while (curr != NULL)
        {
            if (visited[curr] == true)
            {
                return true;
            }
            visited[curr] = true;
            curr = curr->next;
        }

        return false;
    }
};

// Approach 2 : Floyd Cycle Detection
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution
{
public:
    bool detectLoop(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        Node *slow = head;
        Node *fast = head;
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
                return true;
            }
        }
        return false;
    }
};