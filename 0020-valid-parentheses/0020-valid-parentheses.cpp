class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        int count1=0;
        int count2=0;
        for(char i:s){
            if(i=='(' || i=='{' || i=='['){
                st.push(i);
                count1++;
            }
              else{
                if(st.empty()){
                    return false;
                }
                else{ 
                 char x=st.top();
                 st.pop();
                 if(i==')' && x=='(') count2++;
                 if(i==']' && x=='[') count2++;
                 if(i=='}' && x=='{') count2++;
                  }
                }
            }
        return count1==count2;
    }
};