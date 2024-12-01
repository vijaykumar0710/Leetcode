class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }
       int maxLength=0;
       for(auto &num:nums){
        int firstNum=num;
        if(mp.find(firstNum+1)!=mp.end()){
        maxLength=max(maxLength,mp[firstNum]+mp[firstNum+1]);
          }
       }
       return maxLength;
    }
};