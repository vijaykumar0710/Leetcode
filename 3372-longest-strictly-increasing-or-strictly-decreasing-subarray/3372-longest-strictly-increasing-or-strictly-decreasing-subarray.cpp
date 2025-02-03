class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>inc(n,1);
        vector<int>dec(n,1);
        for(int i=1;i<n;i++){
          if(nums[i]>nums[i-1]){
            inc[i]=inc[i-1]+1;
          }
          if(nums[i]<nums[i-1]){
            dec[i]=dec[i-1]+1;
          }
        }
        return max(*max_element(inc.begin(),inc.end()),*max_element(dec.begin(),dec.end()));
    }
};