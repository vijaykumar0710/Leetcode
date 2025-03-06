class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int res=0;
        unordered_map<int,int>mp;
        for(auto &num:nums){
             mp[num]++;
        }
        for(auto [num,freq]:mp){
            if(freq==2){
                res=res^num;
            }
        }
        return res;
    }
};