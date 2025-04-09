class Solution {
public:
    int maxPower(string s) {
        int n=s.size();
        int cnt=1,res=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
              res=max(res,cnt);
              cnt=1;
            }
        }
        res=max(res,cnt);// compare last group
        return res; 
    }
};