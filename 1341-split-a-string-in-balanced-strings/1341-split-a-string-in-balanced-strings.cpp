class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.size();
        int r_cnt=0,l_cnt=0,cnt=0;
        int i=0;
        while(i<n){
            if(s[i]=='L')l_cnt++;
            if(s[i]=='R')r_cnt++;
            if(l_cnt==r_cnt){
                cnt++;
                l_cnt=0;
                r_cnt=0;
            }
            i++;
        }
        return cnt;
    }
};