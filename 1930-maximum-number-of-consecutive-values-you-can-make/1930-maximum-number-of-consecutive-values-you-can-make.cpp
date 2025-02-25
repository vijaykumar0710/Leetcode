class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n=coins.size();
        sort(begin(coins),end(coins));
        int target=1;
        for(int i=0;i<n;i++){
            if(coins[i]<=target){
                target+=coins[i];
            }else break;
        }
        return target;
    }
};