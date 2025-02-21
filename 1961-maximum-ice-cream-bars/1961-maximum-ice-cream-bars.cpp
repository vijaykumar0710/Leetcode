class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int maxIceCream=0;
        for(auto &cost:costs){
            if(coins>=cost){
               maxIceCream++;
               coins-=cost;
            }
        }
        return maxIceCream;
    }
};