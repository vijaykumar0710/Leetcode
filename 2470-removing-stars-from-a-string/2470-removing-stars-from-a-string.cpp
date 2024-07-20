class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
        stack<char> st;
        for(auto i:s){
        if(i!='*'){
            st.push(i);
        } else{
          st.pop();
            }
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};