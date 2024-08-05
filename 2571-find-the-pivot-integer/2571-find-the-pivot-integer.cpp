class Solution {
public:
    int pivotInteger(int n) {
        int x;
        for(int x=1;x<=n;x++){
            int sum1=x*(x+1)/2;
            int sum2=(n*(n+1)/2)-(x*(x-1)/2);
            if(sum1==sum2) return x;
        }
        return -1;
    }
};