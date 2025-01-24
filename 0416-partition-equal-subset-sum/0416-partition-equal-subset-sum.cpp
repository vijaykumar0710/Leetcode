class Solution {
public:
int n;
int t[10000][201];
bool isPossible(vector<int>&nums,int target,int i){
    if(i==n || target<0) return false;
    if(target==0) return true;
    if(t[target][i]!=-1) return t[target][i];
    return t[target][i]=(isPossible(nums,target-nums[i],i+1) || isPossible(nums,target,i+1));
}
    bool canPartition(vector<int>& nums) {
        n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        memset(t,-1,sizeof(t));
        if(total%2!=0){
            return false;
        }else{
            return isPossible(nums,total/2,0);
        }
        return false;
    }
};