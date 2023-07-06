// Unique Binary Tree Requirements - GFG
//Time Complexity - O(1)
//Space Complexity - O(1)

class Solution
{
public:
    bool isPossible(int a, int b)
    {
        if (a == 2 && b == 2)
        {
            return false;
        }
        if (a == 2 || b == 2)
        {
            return true;
        }
        return false;
    }
};
