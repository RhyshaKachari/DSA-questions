//Reverse words in a given string - GFG

//Approach 1 : Pushing in a stack
//Time Complexity = O(|S|)
//Space Complexity = O(|S|)

class Solution{
    public:
        string reverseWords(string s){
            stack<string> st;
            for(int i = 0 ; i < s.length() ; i++){
                string word = "";
                while(s[i] != '.' && i < s.length()){
                    word += s[i];
                    i++;
                }
            st.push(word);
            }
        string ans="";
        while (st.size()!= 1)
        {
           ans += st.top() + "." ;
           st.pop();
        }
        ans = ans+ st.top();
        return ans;
        }
}