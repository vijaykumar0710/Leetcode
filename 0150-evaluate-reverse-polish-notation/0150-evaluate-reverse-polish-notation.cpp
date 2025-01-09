class Solution {
public:
 bool isOperator(const string& token) {
        return (token == "+" || token == "-" || token == "*" || token == "/");
    }
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        for(int i=0;i<n;i++){ 
            string token=tokens[i];
            if(isOperator(token)){
                int x=st.top();
                st.pop();
                int y=st.top();
                st.pop();
                if(token=="+"){
                    st.push(y+x);
                }
                else if(token=="-"){
                    st.push(y-x);
                }
                else if(token=="*"){
                    st.push(y*x);
                }
                else{
                    st.push(y/x);
                }
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};