class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        vector<long long>vec;
       for(int i=0;i<n;i++){
        vec.push_back(i-nums[i]);
       } 
       unordered_map<long,long>mp;
       long long bad=0;
       for(int i=0;i<n;i++){
          bad+=(i-mp[vec[i]]);
          mp[vec[i]]++;
       }
       return bad;
    }
};