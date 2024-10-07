class Solution {
public:
void subset(vector<int>arr,set<vector<int>>&st,vector<int>&nums,int i,int n){
    if(i>=n){
        st.insert(arr);
        return;
    }
     subset(arr,st,nums,i+1,n); // not take
     arr.push_back(nums[i]);   //take
     subset(arr,st,nums,i+1,n);  //after take
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        subset(arr,st,nums,0,n);
        for(auto &num:st){
            ans.push_back(num);
        }
        return ans;
    }
};