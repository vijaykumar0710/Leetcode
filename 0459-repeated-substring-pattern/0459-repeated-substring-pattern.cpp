class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        for(int l=1;l<=n/2;l++){
            if(n%l==0){ 
            int times=n/l;
            string append=s.substr(0,l);
            string temp="";
            while(times--){
                 temp+=append;
               }
               if(temp==s)
                 return true;
            }
        }
        return false;
    }
};