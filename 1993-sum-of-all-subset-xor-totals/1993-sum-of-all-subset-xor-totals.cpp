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
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>subsets;
        subset(nums,subsets,n);
        int sum=0;
        for(auto &vec:subsets){
            int temp=0;
            for(auto &num:vec){
                temp^=num;
            }
            sum+=temp;
        }
        return sum;
    }
};