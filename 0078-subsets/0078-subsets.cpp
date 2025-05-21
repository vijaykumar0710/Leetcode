class Solution {
public:
void solve(vector<int>& nums,int i,vector<int>op,int n,vector<vector<int>>&res){
if(i==n){
    res.push_back(op);
    return;
}
solve(nums,i+1,op,n,res);
op.push_back(nums[i]);
solve(nums,i+1,op,n,res);
//op.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>op;
        solve(nums,0,op,n,res);
        return res;
    }
};