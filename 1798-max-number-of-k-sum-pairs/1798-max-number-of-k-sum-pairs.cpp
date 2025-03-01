class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
       int cnt=0;
       int n=nums.size();
       for(int i=n-1;i>=0;i--){
         if(mp[k-nums[i]]>0){
            cnt++;
            mp[k-nums[i]]--;
         }else{
            mp[nums[i]]++;
         }
       }
       return cnt;
    }
};