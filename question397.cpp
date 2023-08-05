// Implement Queue using Stacks - Leetcode

// Approach 1 :
//  Time Complexity - O(N)
//  Space Complexity - O(1)

class MyQueue
{
public:
    stack<int> input;
    stack<int> output;
    MyQueue()
    {
    }

    void push(int x)
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        input.push(x);
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int pop()
    {
        if (input.size())
        {
            int x = input.top();
            input.pop();
            return x;
        }
        else
        {
            return -1;
        }
    }

    int peek()
    {
        if (input.size())
        {
            int x = input.top();
            return x;
        }
        else
        {
            return -1;
        }
    }

    bool empty()
    {
        return input.empty();
    }
};

// Approach 2 :
//Time Complexity - O(1) amotized 
//Space Complexity - O(2N)

class MyQueue
{
public:
    stack<int> input;
    stack<int> output;
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.size() == 0)
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    int peek()
    {
        if (output.size() == 0)
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        return ans;
    }

    bool empty()
    {
        if (output.size() == 0)
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.empty();
    }
};