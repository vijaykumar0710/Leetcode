class Solution {
public:
void computeLPS(string &s,vector<int>&LPS){
    int n=s.size();
    LPS[0]=0;
    int len=0;
    int i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            LPS[i]=len;
            i++;
        }else{
            if(len!=0){
                len = LPS[len - 1];
            }else{
                LPS[i]=0;
                i++;
            }
        }
    }
}
    bool repeatedSubstringPattern(string s) {
       int n=s.size();
       vector<int>LPS(n);
       computeLPS(s,LPS);
       int longestprefix=LPS[n-1];
       if(longestprefix>0 && (n%(n-longestprefix))==0) return true;
        return false;
    }
};