class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
       string word;
       stack<string>st;
       while(ss>>word){
       st.push(word);
       }
       string result=st.top();
       st.pop();
      while(!st.empty()){
        result=result+" "+st.top();
        st.pop();
      }
      return result;
    }
};