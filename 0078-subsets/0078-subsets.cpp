class Solution {
public:
void subset(vector<int>&nums,vector<vector<int>>&subsets,int n){
for(int mask=0;mask<(1<<n);mask++){
    vector<int>curr;
    for(int i=0;i<n;i++){
      if(mask & (1<<i))
          curr.push_back(nums[i]);
      }
    subsets.push_back(curr);
  }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>subsets;
        subset(nums,subsets,n);
        return subsets;
    }
};