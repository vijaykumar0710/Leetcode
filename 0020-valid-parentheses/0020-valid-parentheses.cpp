class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        int count=0;
        for(char i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
                count++;
            }
              else{
                if(st.empty()){
                    return false;
                }
                else{ 
                 char x=st.top();
                 st.pop();
                 if(i==')' && x=='(') count--;
                 if(i==']' && x=='[') count--;
                 if(i=='}' && x=='{') count--;
                  }
                }
            }
        return count==0;
    }
};