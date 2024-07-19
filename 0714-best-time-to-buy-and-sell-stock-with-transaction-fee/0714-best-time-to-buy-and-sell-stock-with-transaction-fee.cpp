class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int hold = -prices[0];
        int cash = 0;
        
        for (int i = 1; i < n; ++i) {
            int new_hold = max(hold, cash - prices[i]);
            int new_cash = max(cash, hold + prices[i] - fee);
            hold = new_hold;
            cash = new_cash;
        }
        
        return cash;
    }
};