class Solution {
public:
    string clearDigits(string s) {
         stack<char>st;
         for(auto &ch:s){
           if(isdigit(ch)){
            st.pop();
           }
           else st.push(ch);
         }
         string res="";
        while(!st.empty()){
          res+=st.top();
          st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};