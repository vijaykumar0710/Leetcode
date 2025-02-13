class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto &num:nums){
            mp[num]++;
        }
        for(auto [num,freq]:mp){
          if((k==0 && freq>1)||(k>0 && mp.count(num+k)))
          cnt++;
        }
        return cnt;
    }
};