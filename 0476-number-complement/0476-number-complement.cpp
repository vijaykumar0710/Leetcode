class Solution {
public:
  string comp="";
    int findComplement(int num) {
        if(num==0) return 1;
        while(num>=1){ 
       if(num%2==1) comp+='1';
       else{
        comp+='0';
       }
       num=num/2; 
        }
        reverse(begin(comp),end(comp));

        long long n=comp.length();
        long long sum=0;
        long long p=1;
        for(int i=n-1;i>=0;i--){
         if(comp[i]=='0'){
            sum+=p;
         }else{
            sum+=0;
         }
          p=p*2;
        }
        return sum;
    }
};