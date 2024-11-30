class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto &ch:s){
         if(!st.empty() && isdigit(ch)){
            st.pop();
           }else{
            st.push(ch);
           }
        }
        string word;
        while(!st.empty()){
            word+=st.top();
            st.pop();
        }
        reverse(word.begin(),word.end());
        return word;
    }
};