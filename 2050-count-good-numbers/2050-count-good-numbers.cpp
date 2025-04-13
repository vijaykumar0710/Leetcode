class Solution {
public:
    const int MOD = 1e9 + 7;

    long long powmod(long long a,long long b){
    if(b==0) return 1;
    if(b==1) return a;
    long long x=powmod(a,b/2);
    long long ans=(x%MOD*x%MOD)%MOD;
    if(b%2==1){
      ans=(ans%MOD*a%MOD)%MOD;
    }
    return ans%MOD;
}
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Even indices (0,2,4,...)
        long long oddCount = n / 2;         // Odd indices (1,3,5,...)

        long long goodNums = (powmod(5, evenCount) * powmod(4, oddCount)) % MOD;
        return (int)goodNums;
    }
};
