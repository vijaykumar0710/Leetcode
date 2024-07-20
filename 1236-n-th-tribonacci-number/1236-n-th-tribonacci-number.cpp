class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
       int p0=0;
       int p1=1;
       int p2=1;
       int result=0;
       for(int i=3;i<=n;i++){
        result=p0+p1+p2;
        p0=p1;
        p1=p2;
        p2=result;
       }
       return result;
    }
};