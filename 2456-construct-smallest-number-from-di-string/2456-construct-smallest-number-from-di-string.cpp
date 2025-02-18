class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.size();
        string num="";
        stack<char>st;
        int cnt=1;
        for(int i=0;i<=n;i++){
           st.push(cnt+'0');
           cnt++;
           if(pattern[i]=='I' || i==n){
            while(!st.empty()){ 
            num+=st.top();
            st.pop();
             }
           }
        }
        return num;
    }
};