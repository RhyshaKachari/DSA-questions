// Stack using two queues - GFG

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.size() == 0)
    {
        return -1;
    }
    else
    {
        int ans = q1.front();
        q1.pop();
        return ans;
    }
}

// Approach 2 :  Using One queue
// Time Complexity - O(n)
// Space Complexity - O(n)

class MyStack
{
public:
    queue<int> q1;
    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
        int size = q1.size();
        for (int i = 0; i < size - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top()
    {
        int x = q1.front();
        return x;
    }

    bool empty()
    {
        return q1.empty();
    }
};