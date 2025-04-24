class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums) mp[num]++;
        int k=mp.size();
        int cnt=0;
       for(int i=0;i<n;i++){
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            st.insert(nums[j]);
            if(st.size()==k){
                cnt++;
            }
          }
       }
       return cnt;
    }
};