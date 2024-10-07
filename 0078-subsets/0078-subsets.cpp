class Solution {
public:
void subset(vector<int>arr,vector<vector<int>>&ans,vector<int>&nums,int i,int n){
    if(i>=n){
        ans.push_back(arr);
        return;
    }
     subset(arr,ans,nums,i+1,n);
     arr.push_back(nums[i]);
     subset(arr,ans,nums,i+1,n);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        vector<vector<int>>ans;
        subset(arr,ans,nums,0,n);
        return ans;
    }
};