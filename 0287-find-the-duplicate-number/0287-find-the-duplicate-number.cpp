class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
       for(auto &num:mp){
        int x=num.first;
        int y=num.second;
        if(y>1) return x;
       }
       return -1;
    }
};