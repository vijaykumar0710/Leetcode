class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0;
        int n=s.length();
        int zeros=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') zeros++;
            if(s[i]=='1') swaps+=zeros;
        }
        return swaps;
    }
};