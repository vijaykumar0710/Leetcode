class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ngr(n);
        int maxi=prices[n-1];
        ngr[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--){
           if(prices[i]>maxi){
            maxi=prices[i];
           }
           ngr[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(ngr[i]-prices[i]));
        }
        return ans;
    }
};