class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int maxi=0;
        for(int i=0;i<n-1;i++){
            int zeros=0,ones=0;
            for(int j=i;j>=0;j--){
                if(s[j]=='0') zeros++;
            }
             for(int k=i+1;k<n;k++){
                if(s[k]=='1') ones++;
            }
            maxi=max(maxi,(zeros+ones));
        }
        return maxi;
    }
};