class Solution {
public:
int M,N,K;
int MOD=1e9+7;
int t[51][51][101];
int solve(int idx,int searchCost,int maxSofar){
    if(t[idx][searchCost][maxSofar]!=-1) return t[idx][searchCost][maxSofar];
    if(idx==N){
        if(searchCost==K){
            return 1;
        }
        return 0;
    }
    int result=0;
    for(int i=1;i<=M;i++){
        if(i>maxSofar){
           result=(result+solve(idx+1,searchCost+1,i))%MOD;
        }else{
             result=(result+solve(idx+1,searchCost,maxSofar))%MOD;
        }
    }
    return t[idx][searchCost][maxSofar]=result%MOD;
}
    int numOfArrays(int n, int m, int k) {
        memset(t,-1,sizeof(t));
        N=n;
        M=m;
        K=k;
        return solve(0,0,0);
    }
};