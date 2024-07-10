class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for(auto &log:logs){
            if(log=="../"){
                if(!st.empty()){
                    st.pop();
                }
            }else if(log!="./"){
                st.push(log);
            }
        }
        return st.size();
    }
};