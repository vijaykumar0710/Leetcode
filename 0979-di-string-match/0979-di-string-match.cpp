class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.length();
        int inc=0,dec=n;
        vector<int>res(n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='I'){
                res[i]=inc;
                inc++;
            }
            else{
                res[i]=dec;
                dec--;
            }
        }
        if(s[n-1]=='I') res[n]=inc;
        if(s[n-1]=='D') res[n]=dec;
        return res;
    }
};