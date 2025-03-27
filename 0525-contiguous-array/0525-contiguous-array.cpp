class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n=nums.size();
       vector<int>prefix_sum(n);
       prefix_sum[0]=(nums[0]==0)?-1:nums[0];
       for(int i=1;i<n;i++){
        prefix_sum[i]=prefix_sum[i-1]+((nums[i]==0)?-1:nums[i]);
       }
       int max_size=0;
       unordered_map<int,int>mp;
       mp[0]=-1;
       for(int i=0;i<n;i++){
        if(mp.find(prefix_sum[i])!=mp.end()){
            max_size=max(max_size,(i-mp[prefix_sum[i]]));
        }
       else mp[prefix_sum[i]]=i;
       }
       return max_size;
    }
};