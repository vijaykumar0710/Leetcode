class Solution {
public:
bool knapsack(vector<int>&nums,int target,int n){
    vector<vector<int>>t(n+1,vector<int>(target+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0){
            t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
              t[i][j]=(t[i-1][j-nums[i-1]] || t[i-1][j]);
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][target];
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum%2!=0) return false;
        return knapsack(nums,sum/2,n);
    }
};