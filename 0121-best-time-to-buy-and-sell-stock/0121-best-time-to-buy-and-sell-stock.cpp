class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0;
        int buy=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            else{
                int profit=prices[i]-buy;
                maxi=max(maxi,profit);
            }
        }
        return maxi;
    }
};