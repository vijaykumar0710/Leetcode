class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        vector<int>prefixSum_0(n);
        vector<int>suffixSum_1(n);

        if(s[0]=='0'){
            prefixSum_0[0]=1;
        }else{
            prefixSum_0[0]=0;
        }
        for(int i=1;i<n;i++){
         if(s[i]=='0'){
            prefixSum_0[i]=prefixSum_0[i-1]+1;
        }else{
            prefixSum_0[i]=prefixSum_0[i-1];
           }
        }

          if(s[n-1]=='1'){
            suffixSum_1[n-1]=1;
        }else{
            suffixSum_1[n-1]=0;
        }
        for(int i=n-2;i>=0;i--){
         if(s[i]=='1'){
            suffixSum_1[i]=suffixSum_1[i+1]+1;
        }else{
            suffixSum_1[i]=suffixSum_1[i+1];
          }
        }
         int maxi=0;
         for(int i=0;i<n-1;i++){
            maxi=max(maxi,(prefixSum_0[i]+suffixSum_1[i+1]));
         }
         return maxi;
    }
};