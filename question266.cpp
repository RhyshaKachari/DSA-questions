// N meetings in one room -  GFG

// Approach 1 : Greedy Approach - We will sort all the meetings in increasing order of their end times. A meeting can be held if the start time of it is greater than the end time of the previous meeting

//Time Complexity - O(N log N)
//Space Complexity - O(N)

class Solution
{
    struct meeting
    {
        int start ; 
        int end ; 
        int pos; 
    };
    
    static bool cmp(struct meeting m1 ,struct meeting m2){
        if(m1.end < m2.end){return true ;}
        else if(m1.end > m2.end){return false ;}
        else if(m1.pos < m2.pos){return true ;}
        return false; 
    }
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {   struct meeting meet[n] ;
        for(int i = 0 ; i < n ; i++){
            meet[i].start = start[i] ;
            meet[i].end = end[i] ;
            meet[i].pos = i ;
        }

        sort(meet , meet+n , cmp) ;
        vector<int>meets ;
        int limit = meet[0].end ; 
        meets.push_back(meet[0].pos) ; 

        for(int i  = 0  ; i < n ; i++){
            if(meet[i].start > limit){
                limit = meet[i].end ;
                meets.push_back(meet[i].pos) ;
            }
        }
        return meets.size(); 
    }
};