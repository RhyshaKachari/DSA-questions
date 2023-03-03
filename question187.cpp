// Subarray with given sum - Geeks For Geeks

// Approach 1
// Time Complexity = O(n^2)
// Space Complexity :  O(1)

class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        long long curr = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            curr = arr[i];
            if (curr == s)
            {
                v.push_back(i);
                v.push_back(i);
                return v;
            }
            for (int j = i + 1; j < n; j++)
            {
                curr += arr[j];
                if (curr == s)
                {
                    v.push_back(i + 1);
                    v.push_back(j + 1);
                    return v;
                }
                else if (curr > s)
                {
                    break;
                }
            }
        }
        if (v.size() == 0)
        {
            v.push_back(-1);
            return v;
        }
    }
};


// Approach 2 :
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        if (s == 0)
        {
            return {-1};
        }
        long long curr = 0;
        int i = 0;
        int j = 0;
        while (j < n)
        {
            if (curr < s)
            {
                curr = curr + arr[j];
            }

            while (curr > s)
            {
                curr -= arr[i];
                i++;
            }

            if (curr == s)
            {
                return {i + 1, j + 1};
            }
            j++;
        }
        return {-1};
    }
};