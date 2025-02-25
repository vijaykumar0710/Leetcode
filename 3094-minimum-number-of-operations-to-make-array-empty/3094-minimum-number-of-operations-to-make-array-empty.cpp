class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums){
           mp[num]++;
        }
        int minOperations=0;
        for(auto &[_,freq]:mp){
            if(freq==1) return -1;
            minOperations+=freq/3;
            if(freq%3!=0){
            minOperations++;
            }
        }
        return minOperations;
    }
};