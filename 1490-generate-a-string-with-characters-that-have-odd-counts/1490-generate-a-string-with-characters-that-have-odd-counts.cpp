class Solution {
public:
    string generateTheString(int n) {
        string res="";
        if(n%2!=0){
         for(int i=0;i<n;i++){
            res+='a';
         }
        }else{
            int m=n/2;
            if(m%2!=0){ 
            for(int i=0;i<(n/2);i++){
             res+='a';
            }
            for(int i=n/2;i<(n);i++){
             res+='b';
              }
            }else{
                int k=m+1;
                for(int i=0;i<k;i++){
                    res+='a';
                }
                for(int i=k;i<n;i++){
                    res+='b';
                }
            }
        }
        return res;
    }
};