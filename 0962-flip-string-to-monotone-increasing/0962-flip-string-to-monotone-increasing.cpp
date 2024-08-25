class Solution {
public:
int n;
int t[100000+1][00000000000000000000000000000000000000000000000000000000000000000000000000000002];
int solve(string &s,int currIdx,int prev){
   if(currIdx>=n) return 0;
   int flip=INT_MAX;
   int no_flip=INT_MAX;
   if(t[currIdx][prev]!=-1) return t[currIdx][prev];
   if(s[currIdx]=='0'){
    if(prev==0){ 
     flip=1+solve(s,currIdx+1,1);
     no_flip=solve(s,currIdx+1,0);
    }else{
         flip=1+solve(s,currIdx+1,1);
     }
   }
    else{
       if(prev==0){
         flip=1+solve(s,currIdx+1,0);
         no_flip=solve(s,currIdx+1,1);
       }else{
         no_flip=solve(s,currIdx+1,1);
     }
   }
   return t[currIdx][prev]=min(flip,no_flip);
}
    int minFlipsMonoIncr(string s) {
        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(s,0,0);
    }
};