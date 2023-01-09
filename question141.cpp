//Max Rectangle - GFG
//Time Complexity = O(m*n)
//Space Complexity = O(n)

class Solution{
    public:
    vector<int> left(vector<int> &row){
        int n = row.size();
        vector<int> v ;
        stack<pair<int,int>>s;
        int pseudo =  -1;
        for(int i = 0 ; i  < n ; i ++){
        if(s.size() == 0){
           v.push_back(pseudo); 
        }
        else if(s.size()> 0 && s.top().first< row[i]){
            v.push_back(s.top().second);
        }
        else{
            while(s.size() > 0 && s.top().first>= row[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(pseudo);
            }
            else{
                v.push_back(s.top().second);
            }
        }
    
        s.push({row[i] , i});
        }
        return v;
    }
    public:
    vector<int> right(vector<int> &row){
        int n = row.size();
        vector<int> v ;
        stack<pair<int , int>>s;
        int pseudo =  n;
        for(int i = n-1 ; i >= 0 ; i --){
        if(s.size() == 0){
           v.push_back(pseudo); 
        }
        else if(s.size()> 0 && s.top().first< row[i]){
            v.push_back(s.top().second);
        }
        else{
            while(s.size() > 0 && s.top().first>= row[i]){
                s.pop();
            }
            if(s.size() == 0){
                v.push_back(pseudo);
            }
            else{
                v.push_back(s.top().second);
            }
        }
    
        s.push({row[i] , i});
        }
        reverse(v.begin() , v.end()) ;
        return v;
    }
    public:
    int mah(vector<int> &vec){
        int n = vec.size();
        vector<int> l = left(vec);
        vector<int> r= right(vec);
        vector<int> v;
        int mx = INT_MIN;
        for(int i = 0; i < n ; i++){
            int a = (r[i] - l[i] -1)*vec[i];
            if(mx < a){
                mx = a;
            }
        }
        return mx;
    }
    public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> v ;
        for (int j = 0; j < m; j++)
        {
            v.push_back(M[0][j]);
        }
        int mx = mah(v);
        for(int i = 1 ;i<n ; i ++){
            for(int j = 0 ; j < m ;j++){
                if(M[i][j] == 0){
                    v[j]  = 0;
                }
                else{
                    v[j] = v[j] + M[i][j];
                }
            } mx = max( mx , mah(v));
           
        }
        return mx; // Your code here
    }
};