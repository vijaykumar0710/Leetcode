class Solution {
public:
void solve(string &s,int i,string op,vector<string>&res,int n){
if(i==n){
    res.push_back(op);
    return;
    }
    solve(s,i+1,op+s[i],res,n);
    if(isalpha(s[i])){
        if(isupper(s[i])){ 
        char ch=tolower(s[i]);
        solve(s,i+1,op+ch,res,n);
        }
        else{
        char ch=toupper(s[i]);
        solve(s,i+1,op+ch,res,n);
        }
    }
}
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        string op="";
        vector<string>res;
        solve(s,0,op,res,n);
        return res;
    }
};