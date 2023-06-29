// Copy List with Random Pointer - Leetcode

// Approach 1 : Using hashmap
//  Time Complexity - O(n)+ O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> hashMap;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            hashMap[temp] = newNode;
            temp = temp->next;
        }

        Node *t = head;
        while (t != NULL)
        {
            Node *deepNode = hashMap[t];
            deepNode->next = (t->next != NULL) ? hashMap[t->next] : NULL;
            deepNode->random = (t->random != NULL) ? hashMap[t->random] : NULL;
            t = t->next;
        }
        return hashMap[head];
    }
};

// Approach 2 : Optimised Approach
// Time Complexity - O(n) + O(n) + O(n)
// Space Complexity - O(1)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        // step 1
        while (temp != NULL)
        {
            Node *deepnode = new Node(temp->val);
            deepnode->next = temp->next;
            temp->next = deepnode;
            temp = temp->next->next;
        }

        // step 2
        Node *itr = head;
        while (itr != NULL)
        {
            if (itr->random != NULL)
            {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }

        // step 3
        Node *dummy = new Node(0);
        itr = head;
        temp = dummy;
        Node *fwd;
        while (itr != NULL)
        {
            fwd = itr->next->next;
            temp->next = itr->next;
            itr->next = fwd;
            temp = temp->next;
            itr = fwd;
        }
        return dummy->next;
    }
};