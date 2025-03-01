class Solution {
public:
int knapsack(vector<int>&coins,int amount,int n){
    vector<vector<long>>t(n+1,vector<long>(amount+1));
       for(int i=0;i<n+1;i++){
           t[i][0]=0;
         }
         for(int j=1;j<amount+1;j++){
            t[0][j]=INT_MAX-1;
         }
       for(int j=1;j<amount+1;j++){
        if(j%coins[0]==0){
            t[1][j]=j/coins[0];
        }else{
            t[1][j]=INT_MAX-1;
        }
       }
  for(int i=2;i<n+1;i++){
    for(int j=1;j<amount+1;j++){
    if(coins[i-1]<=j){
        t[i][j]=min(t[i-1][j],1+t[i][j-coins[i-1]]);
      }else{
        t[i][j]=t[i-1][j];
      }
    }
  }
  return t[n][amount]==INT_MAX-1?-1:t[n][amount];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        return knapsack(coins,amount,n);
    }
};