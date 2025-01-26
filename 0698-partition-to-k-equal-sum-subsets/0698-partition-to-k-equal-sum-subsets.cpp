class Solution {
public:
int n;
bool canPartition(vector<int>& nums,int target,int start,vector<int>&vis,int currSum,int k){
   if(k==0) return 1;
   if(currSum>target) return 0;
   if(currSum==target){
    return canPartition(nums,target,0,vis,0,k-1);
    }
   for(int i=start;i<n;i++){
    if(!vis[i]){
        vis[i]=1;
        if(canPartition(nums,target,i+1,vis,currSum+nums[i],k)){
            return 1;
        }
        vis[i]=0;
     }
   }
   return 0;
  }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
         n=nums.size();
        int totalSum=accumulate(begin(nums),end(nums),0);
        if(totalSum%k!=0) return false;
        sort(nums.rbegin(), nums.rend());
        vector<int>vis(n,0);
       return canPartition(nums,totalSum/k,0,vis,0,k);
    }
};