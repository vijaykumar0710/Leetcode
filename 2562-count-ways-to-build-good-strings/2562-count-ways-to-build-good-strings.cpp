class Solution {
public:
int t[100001];
   int L,H,Z,O;
   const int MOD=1e9+7;
   int solve(int l){
      if(l>H) return 0;

      bool addOne=false;
      if(t[l]!=-1) return t[l];
      if(l<=H && l>=L){
        addOne=true;
      }

      int append_zero=solve(l+Z);
      int append_one=solve(l+O);

      return t[l]=(addOne+append_zero+append_one)%MOD;
   }
    int countGoodStrings(int low, int high, int zero, int one) {
        L=low;
        H=high;
        Z=zero;
        O=one;
        memset(t,-1,sizeof(t));
        return solve(0);
    }
};