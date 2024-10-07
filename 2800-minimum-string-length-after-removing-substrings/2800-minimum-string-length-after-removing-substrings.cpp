class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(!st.empty()){
                if(st.top()=='A' && s[i]=='B') st.pop();
                else if(st.top()=='C' && s[i]=='D') st.pop();
                 else st.push(s[i]);
              }
            else st.push(s[i]);
            i++;
        }
        return st.size();
    }
};