//Rotate String - Leetcode
//Time Complexity - O(n)
//Space Complexity - O(1)

class Solution
{
public:
   
    bool areRotations(string s1, string s2)
    {
        int l1 = s1.length();
        int i = 0;
        bool ans = false;
        char temp = ' ';
        if (s1 == s2)
            return true;

        for (i = 1; i < l1; i++)
        {
            temp = s1[0];
            s1 = s1.substr(1, l1) + temp;
            if (s1 == s2)
            {
                ans = true;
                break;
            }
        }
        return ans;
    }
};