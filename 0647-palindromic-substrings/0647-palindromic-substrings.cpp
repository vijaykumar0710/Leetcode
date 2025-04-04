class Solution {
public:
bool isPalindrome(string &s,int i,int j){
    int l=i,r=j;
    while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }
        l++,r--;
    }
    return true;
}
    int countSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j))
                   cnt++;
            }
        }
        return cnt;
    }
};