class Solution {
public:
int n;
void backtrack(vector<int>& nums,int idx,set<vector<int>>&st,vector<int>&temp){
  if(idx==n){
    if(temp.size()>=2){
        st.insert(temp);
    }
    return;
  }
  for(int i=idx;i<n;i++){
    backtrack(nums,i+1,st,temp);
    if(temp.empty() || nums[i]>=temp.back()){ 
    temp.push_back(nums[i]);
    backtrack(nums,i+1,st,temp);
    temp.pop_back();
    }
  }
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        set<vector<int>>st;
        vector<int>temp;
        backtrack(nums,0,st,temp);
        vector<vector<int>>res;
        for(auto &vec:st){
            res.push_back(vec);
        }
        return res;
    }
};