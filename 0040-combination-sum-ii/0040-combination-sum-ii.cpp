class Solution {
public:
int n;
void backtrack(vector<int>&candidates,int target,vector<vector<int>>&res,vector<int>&temp,int idx){
  if(target<0) return;
  if(target==0){
    res.push_back(temp);
    return;
  }

  for(int i=idx;i<n;i++){
    if(i>idx && candidates[i]==candidates[i-1]){
        continue;  //ignore duplicate element
    }
    temp.push_back(candidates[i]);
    backtrack(candidates,target-candidates[i],res,temp,i+1);
    temp.pop_back();
  }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>temp;
        backtrack(candidates,target,res,temp,0);
        return res;
    }
};