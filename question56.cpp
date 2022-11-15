//Linked List Insertion - GFG
//Time Complexity - O(n)
//Space Complexity = O(1)

class Solution{
    public:

    //Function to insert a node at the beginning of the linked list
    Node *insertAtBeginning(Node *head , int x){
        Node *curr = new Node(x);
        curr->next = head;
        return curr;
        
    }
    

    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head , int x){
        if (head == NULL)
        {
           Node *curr = new Node(x);
           head = curr;
           return curr;
        }
        Node *curr = head;
        while (curr->next !=NULL){
            curr = curr -> next;

        }
        curr->next = new Node(x);
        return head;
        
        
    }
};