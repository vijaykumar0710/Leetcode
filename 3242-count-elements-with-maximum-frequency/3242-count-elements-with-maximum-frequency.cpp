class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        for(auto &ele:mp){
            maxi=max(maxi,ele.second);
        }
        int freq=0;
         for(auto &idx:mp){
         if(idx.second==maxi){
            freq+=idx.second;
           }
        }
        return freq;
    }
};