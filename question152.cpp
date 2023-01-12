// Majority Element
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution
{
public:
    int majorityElement(int a[], int size)
    {
        int count = 0;
        int ele = 0;
        for (int i = 0; i < size; i++)
        {

            if (count == 0)
            {
                ele = a[i];
            }
            if (ele == a[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (a[i] == ele)
            {
                cnt++;
            }
        }
        if (cnt > size / 2)
        {

            return ele;
        }
        return -1;
    }
};