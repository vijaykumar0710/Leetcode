class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=0;
        while(i<n){
            j=i+1;
            while(j<n){
                if(prices[i]>=prices[j]){
                    prices[i]=prices[i]-prices[j];
                    break;
                  }else{
                    j++;
                }
            }
            i++;
        }
        return prices;
    }
};