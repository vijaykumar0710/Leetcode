class Solution {
public:
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++){
            int n=i,sum=0;
            while(n){
                sum+=n%10;
                n/=10;
            }
            if(sum%2==0) cnt++;
        }
        return cnt;
    }
};