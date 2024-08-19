class Solution {
public:
int t[1001][1001];
int solve(int currA,int clipA,int n){
    if(currA==n){
        return 0;
    }
    if(currA>n){
        return 100000;
    }
     if(t[currA][clipA]!=-1) return t[currA][clipA];
    int copyALLpaste=1+1+solve(currA+currA,currA,n);
    int paste=1+solve(currA+clipA,clipA,n);
    return t[currA][clipA]=min(paste,copyALLpaste);
}
    int minSteps(int n) {
        memset(t,-1,sizeof(t));
        if(n==1) return 0;
        return 1+solve(1,1,n);
    }
};