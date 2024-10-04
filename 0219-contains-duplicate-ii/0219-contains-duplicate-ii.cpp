class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[nums[0]]=0;
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
          if(mp.find(nums[i])!=mp.end()){
            mini=min(mini,abs(i-mp[nums[i]]));
          }
          mp[nums[i]]=i;
        }
        return mini<=k;
    }
};