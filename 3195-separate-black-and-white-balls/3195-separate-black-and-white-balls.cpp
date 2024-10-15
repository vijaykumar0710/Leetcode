class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0;
        int n=s.length();
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
            if(s[i]=='0') swaps+=ones;
        }
        return swaps;
    }
};