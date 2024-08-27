class Solution {
public:
int n;
int t[301][301];
int f(int i,int j,vector<int>&nums){
    if(i>j) return 0;
    int maxi=INT_MIN;
    if(t[i][j]!=-1) return t[i][j];
    for(int k=i;k<=j;k++){
       int coins=nums[i-1]*nums[k]*nums[j+1]+f(i,k-1,nums)+f(k+1,j,nums);

       maxi=max(maxi,coins);
    }
    return t[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
        n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(t,-1,sizeof(t));
        return f(1,n,nums);
    }
};