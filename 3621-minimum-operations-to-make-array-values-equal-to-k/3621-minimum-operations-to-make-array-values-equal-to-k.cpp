class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
        int cnt=0;
        for(auto [num,freq]:mp){
            if(num<k){
                return -1;
            }else if(num>k){
                cnt++;
            }
        }
        return cnt;
    }
};