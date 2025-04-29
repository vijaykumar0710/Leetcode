class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int max_len=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp[nums[j]]>k){
             mp[nums[i]]--;
             i++;
            }
            max_len=max(max_len,(j-i+1));
            j++;
        }
        return max_len;
    }
};