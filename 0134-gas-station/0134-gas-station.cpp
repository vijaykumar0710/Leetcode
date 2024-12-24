class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_earn=accumulate(gas.begin(),gas.end(),0);
        int total_expend=accumulate(cost.begin(),cost.end(),0);
        if(total_expend>total_earn) return -1;

        int total=0;
        int idx=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total=0;
                idx=i+1;
            }
        }
        return idx;
    }
};