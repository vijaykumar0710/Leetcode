class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        stack<char>st;
        int i=0;
       for(auto &ch:s){
        if(!st.empty() && abs(st.top()-ch)==32){
            st.pop();
        }else{
            st.push(ch);
        }
       }
        string res;
        while(!st.empty()){
           res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};