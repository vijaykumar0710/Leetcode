class Solution {
public:
int n;
int solve(vector<int>&coins,int amount,vector<int>&t){
    if(amount==0) return 0;
    if(amount<0) return INT_MAX;
    int minCoin=INT_MAX;
    if(t[amount]!=-1) return t[amount];
    for(int coin:coins){
        int result=solve(coins,amount-coin,t);
        if(result!=INT_MAX){
            minCoin=min(minCoin,result+1);
        }
    }
    return t[amount]=minCoin;
}
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        vector<int>t(amount+1,-1);
         int result=solve(coins,amount,t);
         return result==INT_MAX?-1:result;
    }
};