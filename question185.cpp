//Intersection of Two Arrays - Leetcode
//Time Complexity : O(n^2)
//Space Complexity  : O(n)

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        set<int> s;
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                if (nums1[i] == nums2[j])
                {
                    s.insert(nums1[i]);
                }
            }
        }
        vector<int> v;
        for (auto it : s)
        {
            v.push_back(it);
        }
        return v;
    }
};