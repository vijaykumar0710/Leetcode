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
    int skip=solve(s,k,idx+1,n);
    int take=0;
    for(int j=idx;j<n;j++){
        if(j-idx+1>=k && isPalindrome(s,idx,j)){
            take=1+solve(s,k,j+1,n);
            break;
        }
    }
    return t[idx]=max(take,skip);
}
    int maxPalindromes(string s, int k) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return solve(s,k,0,n);
    }
};