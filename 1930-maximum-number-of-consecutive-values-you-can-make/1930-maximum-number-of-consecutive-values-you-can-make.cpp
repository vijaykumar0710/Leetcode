class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        int sum=0;
        for(int i=0;i<n;i++){
            if(coins[i]<=sum+1){
                sum+=coins[i];
            }else break;
        }
        return sum+1;
    }
};