class Solution {
public:
bool canPartition(vector<int>& nums,int target,int start,vector<int>&vis,int currSum,int k,int n){
   if(k==0) return 1;
   if(currSum>target) return 0;
   if(currSum==target){
    return canPartition(nums,target,0,vis,0,k-1,n);
    }
   for(int i=start;i<n;i++){
    if(!vis[i]){
        vis[i]=1;
        if(canPartition(nums,target,i+1,vis,currSum+nums[i],k,n)){
            return 1;
        }
        vis[i]=0;
     }
   }
   return 0;
  }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int totalSum=accumulate(begin(nums),end(nums),0);
        if(totalSum%k!=0) return false;
        sort(nums.rbegin(), nums.rend());
        vector<int>vis(n,0);
       return canPartition(nums,totalSum/k,0,vis,0,k,n);
    }
};