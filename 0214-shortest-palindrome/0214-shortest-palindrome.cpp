class Solution {
public:
void computeLPS(string &pattern,vector<int>&LPS){
    int m=pattern.size();
    int len=0;
    LPS[0]=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            LPS[i]=len;
            i++;
        }else{
            if(len!=0){
                len=LPS[len-1];
            }else{
                LPS[i]=0;
                i++;
            }
        }
    }
}

    string shortestPalindrome(string s) {
        int n=s.size();
        string rev=s;
        reverse(rev.begin(),rev.end());
        string pattern=s+"_"+rev;
        vector<int>LPS(pattern.size());
        computeLPS(pattern,LPS);
        return rev.substr(0,n-LPS[pattern.size()-1])+s;
    }
};