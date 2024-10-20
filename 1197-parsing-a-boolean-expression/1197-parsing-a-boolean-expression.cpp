class Solution {
public:
char solveOperator(vector<char>&values,char operat){
  if(operat=='!'){
    return values[0]=='t'?'f':'t';
  }
  if(operat=='&'){
    for(char &ch:values){
        if(ch=='f') return 'f';
    }
    return 't';
  }
  if(operat=='|'){
    for(char &ch:values){
        if(ch=='t') return 't';
    }
    return 'f';
  }
  return 't';  //will never come bas aise hi return kardo
}
    bool parseBoolExpr(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]==',') continue;

            if(s[i]==')'){
                vector<char> values;
                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char operat=st.top();
                st.pop();

                st.push(solveOperator(values,operat));
            }else{
                st.push(s[i]);
            }
        }
        return st.top()=='t'?true:false;
    }
};