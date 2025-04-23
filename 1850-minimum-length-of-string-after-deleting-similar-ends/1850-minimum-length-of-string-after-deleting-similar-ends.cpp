class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        int cnt=0;
        while(i<j){
            while(j-i>1 && s[i]==s[i+1]) i++;
            while(j-i>1 && s[j]==s[j-1]) j--;
            if(s[i]==s[j]){
                cnt=(i+1)+(n-j);
                 i++,j--;
            }
           else break;
        }
        return n-cnt;
    }
};