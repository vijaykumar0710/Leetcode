class Solution {
public:
int t[2001];
bool isPalindrome(string &s,int i,int j){
    int l=i,r=j;
    while(l<=r){
        if(s[l]!=s[r])
         return false;
        l++;
        r--;
    }
    return true;
}
int solve(string &s,int k,int idx,int n){
    if(idx>=n){
        return 0;
    }
    if(t[idx]!=-1) return t[idx];
    int res=solve(s,k,idx+1,n);
    for(int j=idx+k-1;j<n;j++){
        if(isPalindrome(s,idx,j)){
            res=max(res,1+solve(s,k,j+1,n));
            break;
        }
    }
    return t[idx]=res;
}
    int maxPalindromes(string s, int k) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return solve(s,k,0,n);
    }
};