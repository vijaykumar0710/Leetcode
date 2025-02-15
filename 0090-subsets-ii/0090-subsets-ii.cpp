class Solution {
public:
void solve(vector<int>& nums,int idx,set<vector<int>>&subset,vector<int>&vec){
if(idx==nums.size()){
    subset.insert(vec);
    return;
   }
   solve(nums,idx+1,subset,vec);
    vec.push_back(nums[idx]);
    solve(nums,idx+1,subset,vec);
    vec.pop_back();
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>subset;
        vector<int>vec;
        sort(nums.begin(),nums.end());
        solve(nums,0,subset,vec);
        vector<vector<int>>res;
        for(auto &temp:subset){
          res.push_back(temp);
        }
        return res;
    }
};