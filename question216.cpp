// Find length of loop - GFG

//Time Complexity = O(n)
//Space Complexity =  O(1)

int countNodesinLoop(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == NULL)
    {
        return 0;
    }

    Node *slow = head;
    Node *fast = head;
    int cnt = 0;
    int flag = 0;
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
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return 0;
    }

    else
    {
        Node *curr = slow->next;
        while (curr != slow)
        {
            curr = curr->next;
            cnt++;
        }
        return cnt + 1;
    }
}