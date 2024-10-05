class Solution {
public:
void generate(vector<string>&ans,string &vec,int op,int col,int n){
if(col==n){
    ans.push_back(vec);
   return;
}
   if(op<n){
    vec+='(';
    op=op+1;
    generate(ans,vec,op,col,n);
    vec.pop_back();
    op--;
   }
    if(op>col){
        vec+=')';
        col=col+1;
    generate(ans,vec,op,col,n);
    vec.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
       string vec="";
        generate(ans,vec,0,0,n);
        return ans;
    }
};