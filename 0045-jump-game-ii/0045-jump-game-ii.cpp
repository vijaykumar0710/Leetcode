class Solution {
public:
int t[10001];
  int canJump(vector<int>&nums,int i,int n){
   if(i==n-1) return 0;
    if(i>=n || nums[i]==0){
        return INT_MAX;
    }    
   int min_path=INT_MAX;
   if(t[i]!=-1) return t[i];
    for(int j=i+1;j<=i+nums[i];j++){
        int mini=canJump(nums,j,n);
        if(mini!=INT_MAX){
           t[i]=min_path=min(mini+1,min_path);
        }
     }
     return t[i]=min_path;
  } 
    int jump(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return canJump(nums,0,n);
    }
};