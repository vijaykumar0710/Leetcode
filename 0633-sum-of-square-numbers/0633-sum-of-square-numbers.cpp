class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++){
           int b=c-i*i;
           int sqrt_b=sqrt(b);
           if(sqrt_b*sqrt_b==b)return true;
        }
        return false;
    }
};