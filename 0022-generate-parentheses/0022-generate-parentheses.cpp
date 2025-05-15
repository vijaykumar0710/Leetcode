class Solution {
public:
void solve(int open,int close,string op,vector<string>&res){
    if(open==0 && close==0){
        res.push_back(op);
        return;
    }
    if(open>0) solve(open-1,close,op+'(',res);
    if(open<close) solve(open,close-1,op+')',res);
}
    vector<string> generateParenthesis(int n) {
        int open=n,close=n;
        string op="";
        vector<string>res;
       solve(open,close,op,res);
       return res;
    }
};