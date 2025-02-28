class Solution {
public:
int knapsack(vector<int>&nums,int s1,int n){
    vector<vector<int>>t(n+1,vector<int>(s1+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<s1+1;j++){
            if(i==0) t[i][j]=0;
            if(j==0) t[i][j]=1;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<s1+1;j++){
            if(nums[i-1]<=j){
                t[i][j]=(t[i-1][j-nums[i-1]] + t[i-1][j]);
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][s1];
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
        if(target>sum || sum+target<0 || (sum+target)%2!=0) return 0;
        int s1=(target+sum)/2;
        return knapsack(nums,s1,n);
    }
};