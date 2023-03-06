//Maximum of all subarrays of size k - GFG

//Approach : Using deque with sliding window
//Time Complexity = O(n)
//Space Complexity = O(k)

class Solution{
    public:
    vector<int> max_of_subarrays(int *arr , int n , int k){
        vector<int> ans;
        deque<int> q;
        int i  = 0 ;
        int j = 0;

        while(j<n){
            while(q.size() > 0 && q.back() < arr[j]){
                q.pop_back();
            }
            q.push_back(arr[j]);

            if(j-i+1 < k){
                j++;
            }

            else if(j- i+1 == k ){
                ans.push_back(q.front());
                if(q.front() == arr[i]){
                    q.pop_front();
                }
                i++ ;
                j++;
            }
        }
        return ans;
    }
};