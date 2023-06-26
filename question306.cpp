// Sort Characters By Frequency- Leetcode

// Approach 1 : Using Priority Queue
// Time Complexity = O(n log n ) + O(n)
// Space Complexity = O(n)

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto it : s)
        {
            mp[it]++;
        }
        priority_queue<pair<int, char>> maxH;
        for (auto it : mp)
        {
            maxH.push({it.second, it.first});
        }
        string ans = "";
        while (maxH.size() > 0)
        {
            int freq = maxH.top().first;
            int c = maxH.top().second;
            while (freq--)
            {
                ans.push_back(c);
            }
            maxH.pop();
        }
        return ans;
    }
};


//Approach 2 : Using maps and hash array

//Time Complexity : O(n)
//Space Complexity : O(n)

class Solution {
public:
   static bool cmp(pair<char ,int>&p1 , pair<char, int>&p2){
        if(p1.second == p2.second){
            return p1.first < p2.first ;
        }
        return p1.second > p2.second ;
    }

public:
    string frequencySort(string s) {
        unordered_map<char ,int>mp;
        for(auto it : s){
            mp[it]++;
        }
        vector<pair<char , int>>count_vec(mp.begin() , mp.end()) ;
        sort(count_vec.begin() , count_vec.end() , cmp);
        string result = "" ;
        for(auto it : count_vec){
            for(int i  = 0 ; i < it.second ; i++){
                result.push_back(it.first) ;
            }
        }
        return result ;

    }
};


