class Solution {
public:
void solve(vector<int>& candidates,int i,int currSum,int target,vector<int>&op,int n,vector<vector<int>>&res){
    if(currSum>target) return;
    if(i==n){
        if(currSum==target) res.push_back(op);
        return;
    }
    solve(candidates,i+1,currSum,target,op,n,res);
    op.push_back(candidates[i]);
    solve(candidates,i,currSum+candidates[i],target,op,n,res);
    op.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>op;
        vector<vector<int>>res;
        solve(candidates,0,0,target,op,n,res);
        return res;
    }
};