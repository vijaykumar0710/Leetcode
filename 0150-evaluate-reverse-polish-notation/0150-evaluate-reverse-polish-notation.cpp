class Solution {
public:
bool isOperator(string& token) {
    // Define a list of valid operators
    vector<string> operators = {"+", "-", "*", "/"};

    // Check if the token matches any operator
    return find(operators.begin(), operators.end(), token) != operators.end();
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
                    y=y+x;
                    st.push(y);
                }
                if(token=="-"){
                    y=y-x;
                    st.push(y);
                }
                if(token=="*"){
                    y=y*x;
                    st.push(y);
                }
                if(token=="/"){
                    y=y/x;
                    st.push(y);
                }
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};