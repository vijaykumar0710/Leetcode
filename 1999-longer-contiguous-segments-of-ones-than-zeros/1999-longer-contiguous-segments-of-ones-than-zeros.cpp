class Solution {
public:
    bool checkZeroOnes(string s) {
        int n=s.size();
        int ones=0,zeros=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
               if(s[i-1]=='1'){ 
                   ones=max(ones,cnt);
               }
                else{
                  zeros=max(zeros,cnt);
                }
                cnt=1;
            }
        }
        if(s[n-1]=='1'){ 
           ones=max(ones,cnt);
             }
              else{
                zeros=max(zeros,cnt);
              }
        return ones>zeros;
    }
};