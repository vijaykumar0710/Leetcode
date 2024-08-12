class Solution {
public:
    bool judgeSquareSum(int c) {
       int n=(c/2)+1;
       for(int i=0;i<=sqrt(c);i++){
        int b=c-i*i;
        if (b<0)break;
         int sqrt_b = sqrt(b);
        if (sqrt_b * sqrt_b == b) return true;
       } 
       return false;
    }
}; 