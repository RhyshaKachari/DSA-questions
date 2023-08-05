// Implement Queues Using Arrays - GFG

// Time Complexity - O(1)
// Space Complexity - O(1)

void MyQueue ::push(int x)
{
    arr[rear] = x;
    rear++;
}

int MyQueue ::pop()
{
    if (front == rear)
    {
        return -1;
    }
    else
    {
        int ans = arr[front];
        front++;
        return ans;
    }
}