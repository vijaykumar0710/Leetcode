class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum=accumulate(begin(gas),end(gas),0);
        int costSum=accumulate(begin(cost),end(cost),0);
        if(costSum>gasSum) return -1;
        int minIdx=0;
        int mini=0;
        for(int i=0;i<cost.size();i++){
          mini+=(gas[i]-cost[i]);
          if(mini<0){
            mini=0;
            minIdx=i+1;
           }
        }
        return minIdx;
    }
};