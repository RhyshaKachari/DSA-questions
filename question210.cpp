// Finding middle element in a linked list - GFG

//Approach 1 : Finding the length first
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int getMiddle(Node *head)
    {
        int len = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            len++;
        }
        int ans = (len / 2) + 1;
        int cnt = 1;
        Node *temp = head;
        while (cnt < ans)
        {
            temp = temp->next;
            cnt++;
        }
        return temp->data;
    }
};


//Approach 2 : Tortoise Hare Method

//Time Complexity = O(n)
//Space Complexity = O(1)

class Solution{
    public:
    int getMiddle(Node *head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;
    }
};