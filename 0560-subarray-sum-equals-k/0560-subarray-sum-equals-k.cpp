class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;// sum of subarray or sum of all elements is zero [-1,1] k=0
        int prefix_sum=0,cnt=0;
        for(auto num:nums){
            prefix_sum+=num;
            if(mp.find(prefix_sum-k)!=mp.end()){
                cnt+=mp[prefix_sum-k];
            }
            mp[prefix_sum]++;
        }
        return cnt;
    }
};