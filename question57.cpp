//Identical Linked Lists
//Time Complexity = O(n)
//Auxilliary Space = O(1)


//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    Node *curr1 = head1;
    Node *curr2 = head2;
    
    
    if(curr1 == NULL && curr2 == NULL){
        return true;
    }
    if(curr1->data != curr2->data){
        return false;
    }
    
    
    while(curr1->next !=NULL && curr2->next != NULL){
        if(curr1->data != curr2->data){
            return false;
        }
         curr1 = curr1->next;
         curr2 = curr2->next;
        
    }
    if(curr1->next != NULL || curr2->next != NULL){
        return false;
    }
    return true;
}