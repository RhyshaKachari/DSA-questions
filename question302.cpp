// Maximum Number of Words Found in Sentences - Leetcode

// Time Complexity - O(n^2)
// Space Complexity - O(1)

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        if (sentences.size() == 0)
        {
            return 0;
        }
        int maxi = INT_MIN;
        int n = sentences.size();
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            for (int j = 0; j < sentences[i].size(); j++)
            {
                if (sentences[i][j] == ' ')
                {
                    count++;
                }
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};