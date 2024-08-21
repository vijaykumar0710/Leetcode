class Solution {
public:
int t[201][10001];
bool helper(vector<int>&nums,int sum,int target,int i){
    if(sum==target) return true;

    if (i >= nums.size() || sum > target) return false;

    if(t[i][sum]!=-1) return t[i][sum];

       bool include=helper(nums,sum+nums[i],target,i+1);

       bool exclude=helper(nums,sum,target,i+1);

    return t[i][sum]=include || exclude;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(auto &num:nums){
            sum+=num;
            cout<<sum;
        }

        memset(t,-1,sizeof(t));
     if(sum%2==0){ 
         return helper(nums,0,sum/2,0);
          }
        return false;
    }
};