class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();
        map<int,long long>mp;
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long curr_sum=nums[i];
            auto it=mp.upper_bound(nums[i]-i);
            if(it!=mp.begin()){
                it--;
                curr_sum+=(*it).second;
            }
            mp[nums[i]-i]=max(mp[nums[i]-i],curr_sum);
            
            // delete which greater in nums but small in value
            it=mp.upper_bound(nums[i]-i); //just greater than nums[i]-i
            while(it!=mp.end() && (*it).second<=curr_sum){
                mp.erase(it++);
            }
            ans=max(ans,curr_sum);
        }
        return ans;
    }
};