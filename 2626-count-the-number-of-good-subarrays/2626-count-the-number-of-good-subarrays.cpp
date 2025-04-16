class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long res=0;
        long long pair=0;
        int i=0,j=0;
        while(j<n){
            pair+=mp[nums[j]];
            mp[nums[j]]++;
            while(pair>=k){
                res+=(n-j);
                mp[nums[i]]--;
                pair-=mp[nums[i]];
                i++;
            }
            j++;
        }
      return res;
    }
};