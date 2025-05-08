class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix_sum(n);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        int small=INT_MAX;
        for(auto x:prefix_sum){
            small=min(small,x);
        }
        if(small<0) return abs(small)+1;
        return 1;
    }
};