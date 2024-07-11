class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxisum=0;
        int sum=0;
        for(auto &vec:accounts){
           for(int &x:vec){
            sum+=x; 
           }
           maxisum=max(maxisum,sum);
           sum=0;
        }
        return maxisum;
    }
};