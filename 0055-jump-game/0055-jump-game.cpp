class Solution {
public:
int t[10001];
bool canjump(vector<int>&nums,int i,int n){
    if(i>=n-1){
        return true;
    }
    //if(nums[i]==0) return false;
    if(t[i]!=-1) return t[i];
    for(int j=i+1;j<=i+nums[i];j++){
        if(canjump(nums,j,n)){
            return t[i]=true;
        }
    }
    return t[i]=false;
}
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return canjump(nums,0,n);
    }
};