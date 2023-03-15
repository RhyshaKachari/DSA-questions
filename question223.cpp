//  Check if Linked List is Palidrome - GFG 

//Time Complexity - O(N)
//Space Complexity - O(1)

class Solution{
public:
int getLength(Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            cnt++;
        }
        return cnt;
    }

    Node *reverse(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *prev = NULL;
        Node *curr = head;
        while (curr != NULL)
        {
            Node *fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
bool isPalindrome(Node *head){
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

        Node *slow = head;
        Node *fast = head->next;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
            }
            slow = slow->next;
        }
        Node *mid = slow;
        if (getLength(head) % 2)
        {
            Node *curr = head;
            Node *newNode = reverse(mid->next);
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
            Node *curr = head;
            while (curr->next != mid)
            {
                curr = curr->next;
            }
            Node *foreven = curr;
            Node *newNode = reverse(mid);
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