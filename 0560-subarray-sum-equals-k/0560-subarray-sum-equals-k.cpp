class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int>mp;
        int prefix_Sum=0;
        for(auto &num:nums){
            prefix_Sum+=num;
            if(prefix_Sum==k) res++;
            res+=mp[prefix_Sum-k];
            mp[prefix_Sum]++;
        }
        return res;
    }
};