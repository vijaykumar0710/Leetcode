class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxisum=0;
        int sum=0;
        for(auto &vec:accounts){
           for(int i=0;i<vec.size();i++){
            sum+=vec[i]; 
           }
           maxisum=max(maxisum,sum);
           sum=0;
        }
        return maxisum;
    }
};