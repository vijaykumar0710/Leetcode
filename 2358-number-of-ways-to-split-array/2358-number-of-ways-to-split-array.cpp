class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long>prefix_sum(n);
        vector<long>suffix_sum(n);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix_sum[i]=prefix_sum[i-1]+nums[i];
        }
        suffix_sum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix_sum[i]=suffix_sum[i+1]+nums[i];
        }
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(prefix_sum[i]>=suffix_sum[i+1])cnt++;
        }
        return cnt;
    }
};