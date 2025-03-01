class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
       int cnt=0;
       for(auto &num:nums){
         if(mp[k-num]>0){
            cnt++;
            mp[k-num]--;
         }else{
            mp[num]++;
         }
       }
       return cnt;
    }
};