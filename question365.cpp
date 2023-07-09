//Rotate List - Leetcode

//Approach 1 : we will rotate the list manually that is iterate through the list till the last node and then add the last node to the front head ;

//Time Complexity - O(n * k)
//Space Complexity - O(1)

//Approach 2 : 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0){
            return head; 
        }

        //finding the height
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != NULL){
            temp = temp->next ;
            cnt++;
        }
        //to make it circular
        temp->next = head;
        k = k%cnt ;
        int end = cnt - k ;
        while(end--){
            temp = temp->next ;
        }
        head = temp->next;
        temp->next = NULL;
        return head; 
    }
};