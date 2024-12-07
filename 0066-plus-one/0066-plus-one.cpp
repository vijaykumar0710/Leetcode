class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();

        vector<int>result(n+1,0);
        bool flag=true;
         for(int i=0;i<n;i++){
            if(digits[i]!=9){
                flag=false;
            }
         }

        if(flag==true){
            for(int i=1;i<result.size();i++){
               result[0]=1;
               result[i]=0;
            }
        }

           if(flag==false){ 
        if(digits[n-1]!=9){
            digits[n-1]=digits[n-1]+1;
        }else{
            int i=n-1;
            while(i>=0 && digits[i]==9){
                digits[i]=0;
                i--;
            }
            digits[i]=digits[i]+1;
             }
           }

        if(flag==true){
            return result;
        } 
        return digits;
    }
};