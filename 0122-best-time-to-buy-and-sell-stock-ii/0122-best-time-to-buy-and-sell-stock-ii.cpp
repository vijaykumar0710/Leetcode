class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int totalProfit=0;
        for(int i=1;i<n;i++){
        if(prices[i]>prices[i-1]){
            int profit=prices[i]-prices[i-1];
            totalProfit+=profit;
           }
        }
        return totalProfit;
    }
};