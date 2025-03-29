class Solution {
public:
int t[101][101][601];
int knapsack(vector<string>&strs,int m,int n,int idx,int size){
if(idx==size || m==0 && n==0){
   return 0;
}
if(t[m][n][idx]!=-1) return t[m][n][idx];
int skip=knapsack(strs,m,n,idx+1,size);
int take=0;
string str=strs[idx];
int zeros=0,ones=0;
for(auto ch:str){
    if(ch=='0')
       zeros++;
    else if(ch=='1')
        ones++;
}
if(zeros<=m && ones<=n){
    take=1+knapsack(strs,m-zeros,n-ones,idx+1,size);
}
return t[m][n][idx]=max(take,skip);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        memset(t,-1,sizeof(t));
        return knapsack(strs,m,n,0,size);
    }
};