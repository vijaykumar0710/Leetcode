class Solution {
public:
bool ispalindrome(string &str,int l,int r){
    while(l<=r){
        if(str[l]!=str[r])
           return false;
           l++;
           r--;
    }
    return true;
}
void solve(string &s,int start,vector<vector<string>>&res,vector<string>&curr,int n){
    if(start==n){
        res.push_back(curr);
        return;
    }
    for(int i=start;i<n;i++){
       if(ispalindrome(s,start,i)){
        curr.push_back(s.substr(start,i-start+1));
        solve(s,i+1,res,curr,n);
        curr.pop_back();
       }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<string>>res;
        vector<string>curr;
        solve(s,0,res,curr,n);
        return res;
    }
};