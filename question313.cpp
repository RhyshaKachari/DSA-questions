// Intersection of Two Linked Lists - LEETCODE

// Approach 1 :  Checking similarity for each node
//  Time Complexity - O(M*N)
//  Space Complexity - O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        while (headB != NULL)
        {
            ListNode *temp = headA;
            while (temp != NULL)
            {
                if (temp == headB)
                {
                    return temp;
                }
                else
                {
                    temp = temp->next;
                }
            }
            headB = headB->next;
        }
        return NULL;
    }
};

// Approach 2 : Hashing
//Time Complexity - O(n+m)
//Space Complexity - O(n)

ListNode *intersectionPresent(ListNode *headA, ListNode *headB)
{
    unordered_set<ListNode *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}


// Approach 3 : Optimised
// Time Complexity - O(2* max(n,m)) + +O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// Space Complexity - O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
        {
            return NULL;
        }

        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = a == NULL ? headB : a->next;
            b = b == NULL ? headA : b->next;
        }

        return a;
    }
};