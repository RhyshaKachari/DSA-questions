// Geek's Training - GFG

// Approach 1 : Recursion
// Time Complexity = O(2^N)  (This solution will give TLE)
// Space Complexity = O(N)

class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &points)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[day][task] + f(day - 1, task, points);
                maxi = max(maxi, point);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        return f(n - 1, 3, points);
    }
};

// Approach 2 : Memoization
// Time Complexity = O(N *4 * 3) 4 different states at max is possible and at every state we are running a for loop of size 3
// Space Complexity = O(N) + O(N*4) = O(N)

class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &points)
    {
        if (day == 0)
        {
            int maxi = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[day][task] + f(day - 1, task, points);
                maxi = max(maxi, point);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        return f(n - 1, 3, points);
    }
};

// Approach 3 : Tabulation
// Time Complexity : O(N*3*4)
// Space Complexity : O(N*4)

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int point = points[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

// Approach 4 : Space Optimisation
// Time Complexity  : O(N*3*4)
// Space Complexity : O(4) = O(1)

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &points, int n)
    {
        vector<int> prev(4, 0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++)
            {
                temp[last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {

                        temp[last] = max(temp[last], points[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};