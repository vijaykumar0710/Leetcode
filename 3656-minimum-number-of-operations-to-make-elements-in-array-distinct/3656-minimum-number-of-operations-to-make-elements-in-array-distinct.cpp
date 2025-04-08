class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0;
        int idx=-1;
         for(int i=n-1;i>=0;i--){
            if(mp.find(nums[i])!=mp.end()){
               idx=i;
               break;
            }
            mp[nums[i]]=i;
         }
         if((idx+1)%3==0){
            return (idx+1)/3;
         }else{
            return ((idx+1)/3)+1;
         }
         return 0;
    }
};