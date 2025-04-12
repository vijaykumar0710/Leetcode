class Solution {
public:

    int countPrimes(int n) {
      //  if(n<3) return 0;
        int cnt=0;
      vector<bool>isPrime(n+1,true);
      for(int i=2;i<=sqrt(n);i++){
        if(isPrime[i]){
            for(int j=2;i*j<=n;j++){
               isPrime[i*j]=false;
            }
        }
      }
      for(int i=2;i<n;i++){
        if(isPrime[i])
         cnt++;
      }
        return cnt;
    }
};