class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
        vector<int>res;
     for(auto &num:mp){
         if(mp[num.first]==2){
            res.push_back(num.first);
         }
     }
     return res;
    }
};