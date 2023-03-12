// Reverse a Linked List in groups of given size - GFG

// Time Complexity = O(n)
// Space Complexity = O(n)

class Solution
{
public:
    struct node *solve(struct node *head, int k)
    {
        // base condition
        if (head == NULL)
        {
            return head;
        }

        // reversing first k nodes
        node *curr = head;
        node *prev = NULL;
        node *fwd = NULL;
        int cnt = 0;
        while (curr != NULL && cnt < k)
        {
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
            cnt++;
        }
        // Recursion aage ka dekhlega
        if (fwd != NULL)
        {
            head->next = solve(fwd, k);
        }
        return prev;
    }

    struct node *reverse(struct node *head, int k)
    {
        return solve(head, k);
    }
};
