class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,vector<int>>idx_mp;
        for(int i=0;i<n;i++){
            idx_mp[nums[i]].push_back(i);
        }

        unordered_map<int,int>mp;
        int maxFreq=0;
        for(auto &num:nums){
            mp[num]++;
            maxFreq=max(maxFreq,mp[num]);
        }
    
       vector<int>vec;
       for(auto [ele,freq]:mp){
        if(freq==maxFreq){
            vec.push_back(ele);
         }
       }

       int len=INT_MAX;
       for(auto &num:vec){
        int y=idx_mp[num].back();
        int x=idx_mp[num][0];
        len=min(len,(y-x+1));
       }
        return len;
    }
};