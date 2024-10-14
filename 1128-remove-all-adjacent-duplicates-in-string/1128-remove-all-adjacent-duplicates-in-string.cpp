class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n=s.length();
        st.push(s[n-1]);
        for(int i=n-2;i>=0;i--){
          if(!st.empty() && s[i]==st.top()){
             st.pop();
          }
          else{
            st.push(s[i]);
          }
        }
        string ori="";
        while(!st.empty()){
          ori+=st.top();
          st.pop();
        }
        return ori;
    }
};