// Middle of the Linked List - Leetcode

// Approach 1 : Finding the length of the list first
// Time Complexity = O(n)
// Space Complexity = O(1)

class Solution
{
public:
    int getLength(ListNode *&head)
    {
        ListNode *curr = head;
        int len = 0;
        while (curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        return len;
    }
    ListNode *middleNode(ListNode *head)
    {
        int len = getLength(head);
        int ans = 0;
        ans = (len / 2) + 1;

        ListNode *curr = head;
        int cnt = 1;
        while (cnt < ans)
        {
            curr = curr->next;
            cnt++;
        }
        return curr;
    }
};


//Approach 2 : Tortoise Hare Method

//Time Complexity = O(n)
//Space Complexity = O(1)

class Solution{
    public:
    ListNode* middleNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!= NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
        }
        return slow;
    }
}