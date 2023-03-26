// Maximum Product Subarray - Leetcode

// Appraoch 1 :
// Time Complexity : O(n^3)
// Space Complexity : O(1)

// Approach 2 :
// Time Complexity : O(n^2)
// Space Complexity : O(1)

// Approach 3 :
// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int leftMax = nums[0];
        int rightMax = nums[0];
        bool zeroPresent = false;
        int product = 1;
        int n = nums.size();
        for (auto it : nums)
        {
            product = product * it;
            if (product == 0)
            {
                zeroPresent = true;
                product = 1;
                continue;
            }
            leftMax = max(leftMax, product);
        }
        product = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            product = product * nums[i];
            if (product == 0)
            {
                zeroPresent = true;
                product = 1;
                continue;
            }
            rightMax = max(rightMax, product);
        }
        if (zeroPresent)
        {
            return max(max(leftMax, rightMax), 0);
        }
        return max(leftMax, rightMax);
    }
};


// Approach 4 :
// Time Complexity : O(n)
// Space Complexity : O(1)


class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int product1 = nums[0];
        int product2 = nums[0];
        int result = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int temp = max({nums[i], nums[i] * product1, nums[i] * product2});
            product2 = min({nums[i], nums[i] * product1, nums[i] * product2});
            product1 = temp;
            result = max(product1, result);
        }
        return result;
    }
};
