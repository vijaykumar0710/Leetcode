class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        int cnt=0;
        long long nuksan=INT_MAX;
        for(auto &num:nums){
            if((num^k)>num){
                ans+=(num^k);
                cnt++;
            }
           else ans+=num;

          nuksan=min(nuksan,1ll*abs(num-(num^k)));
        }
        if(cnt%2>0) ans-=nuksan;
        return ans;
    }
};