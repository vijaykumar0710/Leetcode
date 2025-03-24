class Solution {
public:
unordered_map<string,int>dp;
int solve(vector<int>&rods,int idx,int diff,int n){
    if(idx==n){
     if(diff==0){
        return 0;
     }
     return INT_MIN;
    }
    string key=to_string(idx)+"$"+to_string(diff);
    if(dp.count(key)) return dp[key];
    int option1=rods[idx]+solve(rods,idx+1,diff+rods[idx],n);
    int option2=rods[idx]+solve(rods,idx+1,diff-rods[idx],n);
    int option3=solve(rods,idx+1,diff,n);
    return dp[key]=max({option1,option2,option3});
}
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        return solve(rods,0,0,n)/2;
    }
};