class Solution {
public:
int t[21][10001];
int solve(vector<int>&rods,int idx,int diff,int n){
    if(idx==n){
     if(diff==0){
        return 0;
     }
     return INT_MIN;
    }
   if(t[idx][diff+5000]!=-1) return t[idx][diff+5000];
    int option1=rods[idx]+solve(rods,idx+1,diff+rods[idx],n);
    int option2=rods[idx]+solve(rods,idx+1,diff-rods[idx],n);
    int option3=solve(rods,idx+1,diff,n);
    return t[idx][diff+5000]=max({option1,option2,option3});
}
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(t,-1,sizeof(t));
        return solve(rods,0,0,n)/2;
    }
};